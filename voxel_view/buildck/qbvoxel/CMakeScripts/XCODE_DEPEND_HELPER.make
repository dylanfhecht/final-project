# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.qbvoxel.Debug:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/Debug/libqbvoxel.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/Debug/libqbvoxel.a


PostBuild.qbvoxel.Release:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/Release/libqbvoxel.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/Release/libqbvoxel.a


PostBuild.qbvoxel.MinSizeRel:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/MinSizeRel/libqbvoxel.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/MinSizeRel/libqbvoxel.a


PostBuild.qbvoxel.RelWithDebInfo:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/RelWithDebInfo/libqbvoxel.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/RelWithDebInfo/libqbvoxel.a




# For each target create a dummy ruleso the target does not have to exist
