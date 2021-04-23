dwm - dynamic window manager
============================
dwm is an extremely fast, small, and dynamic window manager for X.


## Installation
------------
Clone this repo

Afterwards enter the following command to build and install dwm (if
necessary as root):

    make clean install


Running dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:

    exec dwm


## Configuration
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.


## Patching DWM
-------------
reset the master branch with 'make clean && rm -f config.h && git reset --hard origin/master'

create new branch with 'git branch <<patch_name>>'

apply patch with 'git apply <<path_to_diff>>'

add modified files with 'git add <<file_names>>'

commit with 'git commit <<patch_name>> -m <<patch_name>>'

push with 'git push origin <<branch_name>>'

change to merge branch with 'git checkout <<merge_branch>>'

merge with 'git merge <<patch_branch>>'

fix conflicts

## Included Patches
-------------
#### alwayscenter
All floating windows are centered, like the center patch, but without a rule.
https://dwm.suckless.org/patches/alwayscenter/

#### attachaside
Make new clients get attached and focused in the stacking area instead of always becoming the new master.
https://dwm.suckless.org/patches/attachaside/

#### autostart
This patch will make dwm run "~/.dwm/autostart_blocking.sh" and "~/.dwm/autostart.sh &" before entering the handler loop. One or both of these files can be ommited.

Be aware that dwm will not startup as long as autostart_blocking.sh is running and will stay completely unresponsive. For obvious reasons it is generally a bad idea to start X-applications here :)
https://dwm.suckless.org/patches/autostart/

#### centeredwindowname
A little patch to center the WM_NAME of the currently selected window on the status bar.
https://dwm.suckless.org/patches/centeredwindowname/

#### colorbar
This patch lets you change the foreground and background color of every statusbar element.
Simply change the RGB values in the config.def.h.
https://dwm.suckless.org/patches/colorbar/

#### cyclelayouts
Cycles through all avaiable layouts using MOD-CTRL-, and MOD-CTRL-.
This adds a "NULL, NULL" layout at the end of the list, which should always be the last layout in your list.
https://dwm.suckless.org/patches/cyclelayouts/

#### fakefullscreen
nly allow clients to "fullscreen" into space currently given to them. As an example, this will allow you to view a fullscreen video in your browser on one half of the screen, while having the other half available for other tasks.
https://dwm.suckless.org/patches/fakefullscreen/

#### focusonclick
Switch focus only by mouse click and not sloppy.
https://dwm.suckless.org/patches/focusonclick/

#### fullscreen
Applies the monocle layout with the focused client on top and hides the bar. When pressed again, shows the bar and restores the layout that was active before going fullscreen.
https://dwm.suckless.org/patches/fullscreen/

#### hide vacant tags
This patch prevents dwm from drawing tags with no clients (i.e. vacant) on the bar.
It also makes sure that pressing a tag on the bar behaves accordingly by not reserving reactive regions on the bar for vacant tags.
It also stops drawing empty rectangles on the bar for non-vacant tags as there is no need anymore to distinguish vacant tags and it offers a more visible contrast than if there were filled/empty rectangles.
https://dwm.suckless.org/patches/hide_vacant_tags/

#### movestack
This plugin allows you to move clients around in the stack and swap them with the master. It emulates the behavior off mod+shift+j and mod+shift+k in Xmonad. movestack(+1) will swap the client with the current focus with the next client. movestack(-1) will swap the client with the current focus with the previous client.
https://dwm.suckless.org/patches/movestack/

#### noborder
Remove the border when there is only one window visible.
https://dwm.suckless.org/patches/noborder/

#### pertag
More general approach to taglayouts patch. This patch keeps layout, mwfact, barpos and nmaster per tag.
https://dwm.suckless.org/patches/pertag/

#### restartsig
dwm can now be restarted via MOD+CTRL+SHIFT+Q or by kill -HUP dwmpid
https://dwm.suckless.org/patches/restartsig/

#### save floats
This patch saves size and position of every floating window before it is forced into tiled mode. If the window is made floating again, the old dimensions will be restored.
https://dwm.suckless.org/patches/save_floats/

#### scratchpads
This patch enables multiple scratchpads, each with one asigned window. This enables the same scratchpad workflow that you have in i3.
https://dwm.suckless.org/patches/scratchpads/

#### status2d
Status2d allows colors and rectangle drawing in your DWM status bar. See below an example of my status bar with multi-cpu and battery.
https://dwm.suckless.org/patches/status2d/

#### statuspadding
This makes the amount of horizontal and vertical padding in the status bar into configurable options.
This padding is also applied to StatusText in an equal manner, as opposed to just right padding.
https://dwm.suckless.org/patches/statuspadding/

#### systray
A simple system tray implementation. Multi-monitor is also supported. The tray follows the selected monitor.
In case icons disappear when toggling the bar, try a different font size in dwm. This has helped at least in one case with pidgin.
https://dwm.suckless.org/patches/systray/

#### tagothermonitor
Add functions and keybindings to tag a window to a desired tag on the next (right) or previous (left) monitor from the currently selected monitor.
https://dwm.suckless.org/patches/tagothermonitor/

#### vanitygaps
Inspired by some of the functionality of i3-gaps this patch adds (inner) gaps between client windows and (outer) gaps between windows and the screen edge in a flexible manner.
https://dwm.suckless.org/patches/vanitygaps/

#### viewontag
Follow a window to the tag it is being moved to.
https://dwm.suckless.org/patches/viewontag/

#### zoomswap
This patch swaps the current window (C) with the previous master (P) when zooming.
https://dwm.suckless.org/patches/zoomswap/




















