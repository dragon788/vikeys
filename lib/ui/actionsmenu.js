var blessed = require('blessed');
var widgets = require('./widgets');
var actionsBox, mainBox, editBox;
var myParent;
var items;
var state;
var callback;
var actionform = require('./actionform');

exports.show = function(parent, globalState, clb) {
  myParent = parent;
  state = globalState;
  callback = clb;
  if(!mainBox) initUI();
  updateActions();
  mainBox.show();
  state.getScreen().render();
  actionsBox.focus();
  //state.pushFocus(actionsBox);
};
exports.hide = function() {
  mainBox.hide();
  state.getScreen().render();
}
function updateActions() {
  actionsBox.setItems([]);
  var commands = {};
  var i, label, action, help;
  var editableAction;
  var actionDef;
  for(i = 0; i < state.firmware.MAX_ACTIONS; i++) {
    if(typeof(state.actions[i]) === 'undefined') {
      label = "Empty";
      help = "Empty slot";
    }
    else {
      if(state.actions[i].fn == 'MACRO') label = 'MACRO';
      else label = state.actions[i].fn.slice(7)+" "+state.actions[i].args.join(", ");
      actionDef = state.firmware.actions.filter(function(a) { return a.id === state.actions[i].fn; });
      if(actionDef.length > 0) help = actionDef[0].help;
      else help = "Not recoginzed by vikeys";
    }
    if(i < 10) label = " "+label;
    editableAction = { mapping: "FN"+i, original: state.actions[i], index: i };
    action = state.actions[i];
    if(action) action.index = i;
    commands[" FN"+i+" "+label] = {
      action: editableAction,
      help: help, 
      actionIndex: i + "",
      //prefix: i+'',
      //keys: [i+''],
      callback: function() {
        var self = this;
        actionform.show(editBox, this.action, state, {
          save: function(value) {
            state.debug("Action form sent action event");
            state.debug(value);
            var saveValue ={ mapping: value.mapping, fn: value.id, args: value.args.slice(0) };
            state.actions[self.action.index] = saveValue;
            actionform.hide();
            updateActions();
            actionsBox.focus();
          },
          cancel: function() {
            state.debug("Action form sent cancel event");
            actionform.hide();
            actionsBox.focus();
          }
        });
      }
    }
  }
  actionsBox.setItems(commands);
}
function initUI() {
  mainBox = blessed.box({
    width: '100%',
    left: 0,
    top: '0%',
    bg: 'blue',
    heigth: '100%',
    keys: false
  });
  editBox = widgets.listmenu({
    left: '40%',
    width: '60%',
    top: '0%',
    right: 0,
    bg: 'pink',
    padding: {
      left: 0,
      right: 0
    },
    height: '100%',
    keyListener: state.keyListener(),
    name: "Key menu",
    itemFg: 'white',
    keys: true,
    vi: true,
    mouse: true,
    style: {
      fg: 'white',
      bg: 'blue',
      border: {
        type: 'bg',
        bg: 'black',
        fg: 'blue'
      },
      selected: {
        prefix: 'white',
        fg: 'blue',
        bg: 'white'
      },
      item: {
        prefix: 'white',
        fg: 'white',
        bg: 'blue'
      }
    }
  });
  actionsBox = widgets.listmenu({
    width: '40%',
    heigth: '100%',
    left: '0%',
    itemFg: 'white',
    keyListener: state.keyListener(),
    keys: true,
    padding: {
      left: 1,
      right: 1
    },
    vi: true,
    name: "Group menu",
    mouse: true,
    style: {
      fg: 'white',
      bg: 'blue',
      border: {
        type: 'line',
        bg: 'blue',
        fg: 'blue'
      },
      selected: {
        prefix: 'white',
        fg: 'blue',
        bg: 'white'
      },
      item: {
        prefix: 'white',
        fg: 'white',
        bg: 'blue'
      }
    }
  });

  myParent.append(mainBox);
  actionsBox.on('cancel', function() {
    actionsBox.setItems([]);
    state.getScreen().render();
    callback.cancel();
  });
  actionsBox.on('focus', function() {
    state.setHelp('');
  });
  actionsBox.on('change', function(item, val) {
    state.setHelp(item.help+ ". Press enter/rigth to edit");
  });

  mainBox.append(actionsBox);
  mainBox.append(editBox);
}
