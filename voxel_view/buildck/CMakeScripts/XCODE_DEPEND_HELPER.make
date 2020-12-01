# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.glad.Debug:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Debug/libglad.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Debug/libglad.a


PostBuild.glfw.Debug:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/Debug/libglfw3.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/Debug/libglfw3.a


PostBuild.qbvoxel.Debug:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/Debug/libqbvoxel.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/Debug/libqbvoxel.a


PostBuild.voxel_view.Debug:
PostBuild.glfw.Debug: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Debug/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.glad.Debug: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Debug/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.qbvoxel.Debug: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Debug/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.glad.Debug: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Debug/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.glfw.Debug: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Debug/voxel_view.app/Contents/MacOS/voxel_view
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Debug/voxel_view.app/Contents/MacOS/voxel_view:\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/Debug/libglfw3.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Debug/libglad.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/Debug/libqbvoxel.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Debug/libglad.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/Debug/libglfw3.a
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Debug/voxel_view.app/Contents/MacOS/voxel_view


PostBuild.glad.Release:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Release/libglad.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Release/libglad.a


PostBuild.glfw.Release:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/Release/libglfw3.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/Release/libglfw3.a


PostBuild.qbvoxel.Release:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/Release/libqbvoxel.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/Release/libqbvoxel.a


PostBuild.voxel_view.Release:
PostBuild.glfw.Release: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Release/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.glad.Release: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Release/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.qbvoxel.Release: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Release/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.glad.Release: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Release/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.glfw.Release: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Release/voxel_view.app/Contents/MacOS/voxel_view
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Release/voxel_view.app/Contents/MacOS/voxel_view:\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/Release/libglfw3.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Release/libglad.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/Release/libqbvoxel.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Release/libglad.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/Release/libglfw3.a
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Release/voxel_view.app/Contents/MacOS/voxel_view


PostBuild.glad.MinSizeRel:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/MinSizeRel/libglad.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/MinSizeRel/libglad.a


PostBuild.glfw.MinSizeRel:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/MinSizeRel/libglfw3.a


PostBuild.qbvoxel.MinSizeRel:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/MinSizeRel/libqbvoxel.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/MinSizeRel/libqbvoxel.a


PostBuild.voxel_view.MinSizeRel:
PostBuild.glfw.MinSizeRel: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/MinSizeRel/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.glad.MinSizeRel: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/MinSizeRel/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.qbvoxel.MinSizeRel: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/MinSizeRel/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.glad.MinSizeRel: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/MinSizeRel/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.glfw.MinSizeRel: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/MinSizeRel/voxel_view.app/Contents/MacOS/voxel_view
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/MinSizeRel/voxel_view.app/Contents/MacOS/voxel_view:\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/MinSizeRel/libglfw3.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/MinSizeRel/libglad.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/MinSizeRel/libqbvoxel.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/MinSizeRel/libglad.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/MinSizeRel/libglfw3.a
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/MinSizeRel/voxel_view.app/Contents/MacOS/voxel_view


PostBuild.glad.RelWithDebInfo:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/RelWithDebInfo/libglad.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/RelWithDebInfo/libglad.a


PostBuild.glfw.RelWithDebInfo:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/RelWithDebInfo/libglfw3.a


PostBuild.qbvoxel.RelWithDebInfo:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/RelWithDebInfo/libqbvoxel.a:
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/RelWithDebInfo/libqbvoxel.a


PostBuild.voxel_view.RelWithDebInfo:
PostBuild.glfw.RelWithDebInfo: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/RelWithDebInfo/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.glad.RelWithDebInfo: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/RelWithDebInfo/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.qbvoxel.RelWithDebInfo: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/RelWithDebInfo/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.glad.RelWithDebInfo: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/RelWithDebInfo/voxel_view.app/Contents/MacOS/voxel_view
PostBuild.glfw.RelWithDebInfo: /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/RelWithDebInfo/voxel_view.app/Contents/MacOS/voxel_view
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/RelWithDebInfo/voxel_view.app/Contents/MacOS/voxel_view:\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/RelWithDebInfo/libglfw3.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/RelWithDebInfo/libglad.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/RelWithDebInfo/libqbvoxel.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/RelWithDebInfo/libglad.a\
	/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/RelWithDebInfo/libglfw3.a
	/bin/rm -f /Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/RelWithDebInfo/voxel_view.app/Contents/MacOS/voxel_view




# For each target create a dummy ruleso the target does not have to exist
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Debug/libglad.a:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/MinSizeRel/libglad.a:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/RelWithDebInfo/libglad.a:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/Release/libglad.a:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/Debug/libglfw3.a:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/MinSizeRel/libglfw3.a:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/RelWithDebInfo/libglfw3.a:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/glfw-3.2/src/Release/libglfw3.a:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/Debug/libqbvoxel.a:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/MinSizeRel/libqbvoxel.a:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/RelWithDebInfo/libqbvoxel.a:
/Users/calderking/Documents/GitHub/module-volumetric-models-team-c/voxel_view/buildck/qbvoxel/Release/libqbvoxel.a:
