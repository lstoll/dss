#!/bin/sh
 
##Build script for Darwin Streaming Server debian package

PLAT=`uname`
VERSION=`cat revision.h | grep "kVersionString \"" | cut -d \" -f 2`


# Build the tarball first - this will handle getting everything compiled
./buildtarball
# Remove the tarball & clean the dist staging dir
rm DarwinStreamingSrvr$1-$PLAT.tar.gz
rm -rf DarwinStreamingSrvr$1-$PLAT

# Re-create the root in the dist dir, but not flattened
./DSS_MakeRoot DarwinStreamingSrvr$1-$PLAT $1

# Create and copy the debian files
mkdir DarwinStreamingSrvr$1-$PLAT/DEBIAN
cp -r dpkg/* DarwinStreamingSrvr$1-$PLAT/DEBIAN/

# Append the version number to the control file
echo 'Version: '$VERSION >> DarwinStreamingSrvr$1-$PLAT/DEBIAN/control
# Set the arch to i386 - its the only one supported.
echo 'Architecture: i386' >> DarwinStreamingSrvr$1-$PLAT/DEBIAN/control

# Create the init.d dir in the dist dir, move script over.
mkdir DarwinStreamingSrvr$1-$PLAT/etc/init.d
mv DarwinStreamingSrvr$1-$PLAT/DEBIAN/control/streamingserver DarwinStreamingSrvr$1-$PLAT/etc/init.d/

# Re-name all the config files to .dist
for f in DarwinStreamingSrvr$1-$PLAT/etc/streaming/*; do mv $f $f.dist; done

# Build the package
