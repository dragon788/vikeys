#!/usr/bin/env node
var screenoptions = {};
//console.log(process.argv);
if(process.argv.length > 1) {
  screenoptions.log = "./vikeys.log";
  screenoptions.debug = true;
}
screenoptions.smartCSR= true;
screenoptions.useBCE= true;
screenoptions.forceUnicode= true;
screenoptions.terminal = 'screen-256color';
screenoptions.extended = true;
var blessed = require('blessed');
var screen = blessed.screen(screenoptions);
var widgets = require('./lib/ui/widgets.js');
var keyboard = require('./lib/keyboard');
var keyboards = require('./lib/keyboards');
var state = require('./lib/state')
var menuAssign = require('./lib/ui/assignmenu.js');
var menuActions = require('./lib/ui/actionsmenu.js');
var pjson = require('./package.json');

process.title = "vikeys";
state.setScreen(screen);
state.keyboardModel = keyboards.keyboards['ergodox'];
state.firmware = require('./firmwares/tmk.js');

var ui = blessed.box({
  top: '50%',
  left: '10%',
  right: 0,
  width: '90%',
  height: '50%',
  style: {
    fg: 'white',
    bg: 'blue',
    border: {
      fg: '#f0f0f0'
    }
  },
  keys: 'vi'
});
var keyboardBox = blessed.box({
  top: '0%',
  left: '0%',
  width: '100%',
  height: '50%'
});
var mainMenu = widgets.listmenu({
  width: '10%',
  left: 0,
  top: '50%',
  height: '50%',
  keys: true,
  mouse: true,
  keyListener: state.keyListener(),
  vi: true,
  name: "Main menu",
  style: {
    fg: 'white',
    bg: 'blue',
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
function menuHome() {
  mainMenu.setItems({
    ' Assign': {
      help: "Map keys",
      callback: function() {
        menuAssign.show(ui, state, {
          assign: function(code) {
            state.keys[state.currentKey].setMapping(state.keyboard.getLayer(), code);
            state.keys.forEach(function(key) {
              if(key.isSelected()) {
                key.setMapping(state.layer, code);
                key.select(false);
              }
            });
          },
          cancel: function() {
            menuAssign.hide();
            mainMenu.focus();
          }
        });
      }
    },
    ' Actions': {
      help: "List and edit action functions",
      callback: function() {
        menuActions.show(ui, state, {
          cancel: function() {
            menuActions.hide();
            mainMenu.focus();
          }
        });
      }
    },
    ' Build': {
      help: "Build and upload firmware",
      callback: function() {
        state.setHelp("Not implemented yet");
      }
    },
    ' Load': {  
      help: "Load a keymap file",
      callback: function() {
        var fm = blessed.filemanager({
          keys: true,
          vi: true,
          style: {
            fg: 'white',
            bg: 'blue',
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
        ui.append(fm);
        fm.focus();
        fm.pick('./', function(error, file) {
          if(error || file == "" || typeof(file) === 'undefined' || file == null) {
            ui.remove(fm);
            mainMenu.focus();
            state.redraw();
            return;
          }
          ui.remove(fm);
          load(file);
        });
      }
    }, 
    ' Save': {
      help: "Save the current state",
      callback: function() {
        var saveAs = state.currentFile === null ? (process.cwd()+(process.platform === 'win32' ? '\\' : '/') ) : state.currentFile;
        var saveName = widgets.filebox({
          bottom: 0,
          width: '100%',
          height: 1,
          value: saveAs, 
          style: {
            bg: 'blue',
            fg: 'white'
          }
        });
        state.setHelp("Enter file name to write to");
        state.getStatusBar().bottom = 1;
        screen.append(saveName);
        //saveName.focus();
        saveName.on('completion', function(matches) {
          if(matches === null || matches.length == 1) {
            state.statusExtra = '';
            state.getStatusBar().height = 1;
            state.statusExtra = ''; //matches.join(' ');
          } else {
            state.getStatusBar().height = 2;
            state.statusExtra = matches.join(' ');
          }
          state.redraw();
        });
        saveName.readInput(function(err, path) {
          screen.remove(saveName);
          screen.removeListener('keypress', state.keyListener());
          if(path !== null) {
            state.firmware.save(path, { fn_ids: state.fn_ids, action_fn: state.action_fn, actions: state.actions, keys: state.keys }, state.keyboardModel, function(err, msg) {
              if(err) state.setHelp(err);
              else state.setHelp("Saved to "+path);
              state.getStatusBar().bottom = 0;
              state.getStatusBar().height = 1;
            });
          }
          else {
            state.getStatusBar().bottom = 0;
            state.getStatusBar().height = 1;
            state.setHelp("");
          }
        });
      }
    },
    ' Exit': {
      help: "Exit this program",
      callback: function() {
        process.exit(0);
      }
    }
  });
}
function load(file) {
  state.firmware.load(file, function(error, def) {
    state.currentFile = file;
    state.keyboard.addMappings(def.maps);
    state.actions = def.actions;
    state.fn_ids = def.fn_ids;
    state.action_fn = def.action_fn;
    mainMenu.focus();
    state.setHelp("Loaded "+def.maps.length+" layers, "+def.actions.length+" actions");
    state.redraw();
  });
}
function eventListener(msg) {
  switch(msg) {
    case "redraw": screen.render(); break;
  }
}
// Append our box to the screen.
screen.append(keyboardBox);
screen.append(mainMenu);
screen.append(ui);
//ui.height = mainMenu.height = ui.height - 2;
screen.append(state.getStatusBar());
screen.grabKeys = true;

//state.pushFocus(mainMenu);


state.keyboard = new keyboard.Keyboard(keyboardBox, state.keyboardModel, state);
//state.on('keyboard', keyboard.eventListener);
state.keyboard.on('keypress', state.keyListener());
screen.on('keypress', state.keyListener());
state.redraw();
mainMenu.on('focus', function() {
  state.setHelp('');
});
mainMenu.on('change', function(item, val) {
  state.setHelp(item.help+ "");
});
menuHome();
mainMenu.focus();
if(process.argv.length > 2) load(process.argv[2]);
else state.setHelp("Welcome to vikeys! Use arrows or vi keys to navigate");

