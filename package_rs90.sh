#!/bin/sh

mkdir -p opk
cp build/objviewer opk/objviewer
mkdir opk/assets
cp assets/font.ttf opk/assets/font.ttf

print()
	case    ${IFS- } in
	(\ *)   printf  %b\\n "$*";;
	(*)     IFS=\ $IFS
	printf  %b\\n "$*"
	IFS=${IFS#?}
esac

print '[Desktop Entry]
Type=Application
Name=ObjViewer
Comment=Wavefront Object Viewer
Exec=objviewer
Terminal=false
Type=Application
Categories=applications;
X-OD-NeedsDownscaling=false' > opk/default.rs90.desktop

mksquashfs ./opk objviewer.opk -all-root -noappend -no-exports -no-xattrs

rm -r opk
mv objviewer.opk build/objviewer.opk