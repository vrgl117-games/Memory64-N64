#!/bin/env bash

size='48000'
font='Retro Mono Wide'
font_path="/path/to//Retro Mono Wide.ttf"
gravity="center"


convert -background "#ffffff00" -gravity $gravity   "pango:<span size='$size' font='$font'><span foreground='#880000'>M</span><span foreground='#008800'>E</span><span foreground='#000088'>M</span><span foreground='#888800'>O</span><span foreground='#880000'>R</span><span foreground='#008800'>Y</span><span foreground='#000088'>6</span><span foreground='#888800'>4</span></span>" -font "$font_path"  _logo0.png
convert -background "#ffffff00" -gravity $gravity   "pango:<span size='$size' font='$font'><span foreground='#ff0000'>M</span><span foreground='#008800'>E</span><span foreground='#000088'>M</span><span foreground='#888800'>O</span><span foreground='#880000'>R</span><span foreground='#008800'>Y</span><span foreground='#000088'>6</span><span foreground='#888800'>4</span></span>" -font "$font_path"  _logo1.png
convert -background "#ffffff00" -gravity $gravity   "pango:<span size='$size' font='$font'><span foreground='#880000'>M</span><span foreground='#00ff00'>E</span><span foreground='#000088'>M</span><span foreground='#888800'>O</span><span foreground='#880000'>R</span><span foreground='#008800'>Y</span><span foreground='#000088'>6</span><span foreground='#888800'>4</span></span>" -font "$font_path"  _logo2.png
convert -background "#ffffff00" -gravity $gravity   "pango:<span size='$size' font='$font'><span foreground='#880000'>M</span><span foreground='#008800'>E</span><span foreground='#0000ff'>M</span><span foreground='#888800'>O</span><span foreground='#880000'>R</span><span foreground='#008800'>Y</span><span foreground='#000088'>6</span><span foreground='#888800'>4</span></span>" -font "$font_path"  _logo3.png
convert -background "#ffffff00" -gravity $gravity   "pango:<span size='$size' font='$font'><span foreground='#880000'>M</span><span foreground='#008800'>E</span><span foreground='#000088'>M</span><span foreground='#ffff00'>O</span><span foreground='#880000'>R</span><span foreground='#008800'>Y</span><span foreground='#000088'>6</span><span foreground='#888800'>4</span></span>" -font "$font_path"  _logo4.png
convert -background "#ffffff00" -gravity $gravity   "pango:<span size='$size' font='$font'><span foreground='#880000'>M</span><span foreground='#008800'>E</span><span foreground='#000088'>M</span><span foreground='#888800'>O</span><span foreground='#ff0000'>R</span><span foreground='#008800'>Y</span><span foreground='#000088'>6</span><span foreground='#888800'>4</span></span>" -font "$font_path"  _logo5.png
convert -background "#ffffff00" -gravity $gravity   "pango:<span size='$size' font='$font'><span foreground='#880000'>M</span><span foreground='#008800'>E</span><span foreground='#000088'>M</span><span foreground='#888800'>O</span><span foreground='#880000'>R</span><span foreground='#00ff00'>Y</span><span foreground='#000088'>6</span><span foreground='#888800'>4</span></span>" -font "$font_path"  _logo6.png
convert -background "#ffffff00" -gravity $gravity   "pango:<span size='$size' font='$font'><span foreground='#880000'>M</span><span foreground='#008800'>E</span><span foreground='#000088'>M</span><span foreground='#888800'>O</span><span foreground='#880000'>R</span><span foreground='#008800'>Y</span><span foreground='#0000ff'>6</span><span foreground='#888800'>4</span></span>" -font "$font_path"  _logo7.png
convert -background "#ffffff00" -gravity $gravity   "pango:<span size='$size' font='$font'><span foreground='#880000'>M</span><span foreground='#008800'>E</span><span foreground='#000088'>M</span><span foreground='#888800'>O</span><span foreground='#880000'>R</span><span foreground='#008800'>Y</span><span foreground='#000088'>6</span><span foreground='#ffff00'>4</span></span>" -font "$font_path"  _logo8.png

convert -append _logo*.png logo.png

rm _logo*.png
