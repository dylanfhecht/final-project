#include "common.h"







bool VoxelGrid::loadVoxels(const char * path){

  //decode
  unsigned error = voxelgrid_decode(volume, width, height, depth, path);

  //if there's an error, display it
  if(error){
      std::cout << "decoder error " << error;
      std::cout << ": " << voxelgrid_error_text(error) << std::endl;
    return false;}
    
  
  std::cout << "Volume loaded: " << width << " x " << height << " x " << depth << std::endl;
  std::cout << (width*height*depth) << " voxels.\n";
  std::cout << "Volume has " << volume.size()/(width*height*depth) << "color values per voxel.\n";

  vec3 center = vec3(-(float)width/2.0, -(float)height/2.0, -(float)depth/2.0);
  double max_dim = (std::max)(width, (std::max)(height, depth));

  model_view = RotateX(-45)*
               Scale(1.0/max_dim,
                     1.0/max_dim,
                     1.0/max_dim)*
                     Translate(center);  //Orient Model About Center

  return true;

}


//Create a single triangulated cube at the given position and add it
//to the vertices array. You may want to use this function (or add
//similar functions to the VoxelGrid class) to organize your code.
void VoxelGrid::addCube(vec3 pos) {
    //bottom
 vertices.push_back(vec3(0,0,0)+ pos);
 vertices.push_back(vec3(0,1,0)+ pos);
 vertices.push_back(vec3(1,0,0)+ pos);

 vertices.push_back(vec3(0,1,0)+ pos);
 vertices.push_back(vec3(1,0,0)+ pos);
 vertices.push_back(vec3(1,1,0)+ pos);
   //top
   vertices.push_back(vec3(0,1,1)+ pos);
   vertices.push_back(vec3(1,0,1)+ pos);
   vertices.push_back(vec3(1,1,1)+ pos);
    
    vertices.push_back(vec3(0,0,1)+ pos);
    vertices.push_back(vec3(0,1,1)+ pos);
    vertices.push_back(vec3(1,0,1)+ pos);
    //side back
    
    vertices.push_back(vec3(0,1,0)+ pos);
    vertices.push_back(vec3(0,1,1)+ pos);
    vertices.push_back(vec3(1,1,1)+ pos);

     vertices.push_back(vec3(1,1,1)+ pos);
     vertices.push_back(vec3(1,1,0)+ pos);
     vertices.push_back(vec3(0,1,0)+ pos);
     
    //side east
    
    vertices.push_back(vec3(1,1,1)+ pos);
    vertices.push_back(vec3(1,0,0)+ pos);
    vertices.push_back(vec3(1,1,0)+ pos);
    
    vertices.push_back(vec3(1,1,1)+ pos);
    vertices.push_back(vec3(1,0,1)+ pos);
    vertices.push_back(vec3(1,0,0)+ pos);

    //side west
    vertices.push_back(vec3(0,0,1)+ pos);
    vertices.push_back(vec3(0,0,0)+ pos);
    vertices.push_back(vec3(0,1,0)+ pos);
    
      vertices.push_back(vec3(0,0,1)+ pos);
      vertices.push_back(vec3(0,1,0)+ pos);
      vertices.push_back(vec3(0,1,1)+ pos);
//side front

     vertices.push_back(vec3(0,0,1)+ pos);
     vertices.push_back(vec3(0,0,0)+ pos);
     vertices.push_back(vec3(1,0,0)+ pos);
    
    vertices.push_back(vec3(0,0,1)+ pos);
    vertices.push_back(vec3(1,0,0)+ pos);
    vertices.push_back(vec3(1,0,1)+ pos);
    
    

}

//TODO
//Create a triangulated version of the voxel grid for rendering and populate
//the vertices array.
void VoxelGrid::createMesh(){
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            for(int z = 0; z < depth; z++){
                if (this->volume[(x + y*width + z*width*height)*4+3] != 0){
                addCube(vec3 (x,y,z));
                    createNormals();
                    createColors();
                }
            }
        }
    }
    //addCube(1);
    
    //addCube(vec3 (1,1,0));
    //addCube(vec3 (5,5,0));

}

//TODO
//Populate the normal array with vertice normals for the triangle mesh
void VoxelGrid::createNormals(){
    //bottom
    normals.push_back(vec3(0,0,-1));
    normals.push_back(vec3(0,0,-1));
    normals.push_back(vec3(0,0,-1));
    normals.push_back(vec3(0,0,-1));
    normals.push_back(vec3(0,0,-1));
    normals.push_back(vec3(0,0,-1));

    //top
    normals.push_back(vec3(0,0,1));
    normals.push_back(vec3(0,0,1));
    normals.push_back(vec3(0,0,1));
    normals.push_back(vec3(0,0,1));
    normals.push_back(vec3(0,0,1));
    normals.push_back(vec3(0,0,1));

    //side back
    normals.push_back(vec3(0,1,0));
    normals.push_back(vec3(0,1,0));
    normals.push_back(vec3(0,1,0));
    normals.push_back(vec3(0,1,0));
    normals.push_back(vec3(0,1,0));
    normals.push_back(vec3(0,1,0));

    //side east
    normals.push_back(vec3(1,0,0));
    normals.push_back(vec3(1,0,0));
    normals.push_back(vec3(1,0,0));
    normals.push_back(vec3(1,0,0));
    normals.push_back(vec3(1,0,0));
    normals.push_back(vec3(1,0,0));

    //side west
    normals.push_back(vec3(-1,0,0));
    normals.push_back(vec3(-1,0,0));
    normals.push_back(vec3(-1,0,0));
    normals.push_back(vec3(-1,0,0));
    normals.push_back(vec3(-1,0,0));
    normals.push_back(vec3(-1,0,0));

    //side front
    normals.push_back(vec3(0,-1,0));
    normals.push_back(vec3(0,-1,0));
    normals.push_back(vec3(0,-1,0));
    normals.push_back(vec3(0,-1,0));
    normals.push_back(vec3(0,-1,0));
    normals.push_back(vec3(0,-1,0));
}

//TODO
//Populate the color array with vertice colors for the triangle mesh
void VoxelGrid::createColors(){
   double r,g,b;
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            for(int z = 0; z < depth; z++){
                if(volume[(x + y*width + z*width*height)*4 + 3] != 0){
                    b = volume[(x + y*width + z*width*height)*4 + 2]/255.0;
                    g = volume[(x + y*width + z*width*height)*4 + 1]/255.0;
                    r = volume[(x + y*width + z*width*height)*4]/255.0;

                    for(int c = 0; c < 36; c++){
                        colors.push_back(vec3(r,g,b));
                    }

                }
            }
        }
    }
}
