#!/bin/sh
 
##Build script for Darwin Streaming Server debian package

PLAT=`uname`
VER=`cat revision.h | grep "kVersionString \"" | cut -d \" -f 2`


# Build the tarball first - this will handle getting everything compiled
./buildtarball $VER
# Remove the tarball & clean the dist staging dir
rm DarwinStreamingSrvr$VER-$PLAT.tar.gz
rm -rf DarwinStreamingSrvr$VER-$PLAT

# Re-create the root in the dist dir, but not flattened
./DSS_MakeRoot DarwinStreamingSrvr$VER-$PLAT $VER

# Create and copy the debian files
mkdir DarwinStreamingSrvr$VER-$PLAT/DEBIAN
cp -r dpkg/* DarwinStreamingSrvr$VER-$PLAT/DEBIAN/

# Append the version number to the control file
echo 'Version: '$VERSION >> DarwinStreamingSrvr$VER-$PLAT/DEBIAN/control
# Set the arch to i386 - its the only one supported.
echo 'Architecture: i386' >> DarwinStreamingSrvr$VER-$PLAT/DEBIAN/control

# Create the init.d dir in the dist dir, move script over.
mkdir DarwinStreamingSrvr$VER-$PLAT/etc/init.d
mv DarwinStreamingSrvr$VER-$PLAT/DEBIAN/streamingserver DarwinStreamingSrvr$VER-$PLAT/etc/init.d/

# Re-name all the config files to .dist
for f in DarwinStreamingSrvr$VER-$PLAT/etc/streaming/*; do mv $f $f.dist; done

# Build the package
