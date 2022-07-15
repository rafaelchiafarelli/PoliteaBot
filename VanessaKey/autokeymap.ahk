#Persistent
SetTimer, WatchCursor, 100
return

WatchCursor:
MouseGetPos, xpos, ypos,id, control
WinGetTitle, title, ahk_id %id%
WinGetClass, class, ahk_id %id%
ToolTip, xpos %xpos%`nypos %ypos%
return


^Up::
DllCall("SetCursorPos", "int", 100, "int", 400)  ;
return

^Down::
MouseMove, 300, 400
