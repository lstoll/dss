#!/bin/sh
 
##Build script for Darwin Streaming Server debian package

PLAT=`uname`
VER=`cat revision.h | grep "kVersionString \"" | cut -d \" -f 2`
PACKAGING_DIR=DarwinStreamingSrvr$VER-$PLAT


# Build the tarball first - this will handle getting everything compiled
echo '--- Building linux tarball - to trigger build process'
./buildtarball $VER
# Remove the tarball & clean the dist staging dir
echo '--- Removing results of tarball build'
rm $PACKAGING_DIR.tar.gz
rm -rf $PACKAGING_DIR

# Re-create the root in the dist dir, but not flattened
echo '--- Creating unflatted dist directory'
./DSS_MakeRoot $PACKAGING_DIR $VER

# Create and copy the debian files
echo '--- Creating debian control directory, and copying files over'
mkdir $PACKAGING_DIR/DEBIAN
cp -r dpkg/* $PACKAGING_DIR/DEBIAN/

echo '--- Appending version to control file'
# Append the version number to the control file
echo 'Version: '$VER >> $PACKAGING_DIR/DEBIAN/control

echo '--- creating the init.d dir, moving script from it to control dir'
# Create the init.d dir in the dist dir, move script over.
mkdir $PACKAGING_DIR/etc/init.d
mv $PACKAGING_DIR/DEBIAN/streamingserver $PACKAGING_DIR/etc/init.d/

echo '--- Re-naming the config files to .dist'
# Re-name all the config files to .dist
for f in $PACKAGING_DIR/etc/streaming/*; do mv $f $f.dist; done

# Build the package
dpkg -b $PACKAGING_DIR
