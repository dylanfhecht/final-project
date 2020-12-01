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
    if((pos[1] == 0) || (volume[(pos[0] + (pos[1]-1)*width + pos[2]*width*height)*4 + 3] == 0)){
        vertices.push_back(vec3(0,0,0)+ pos);
        vertices.push_back(vec3(0,1,0)+ pos);
        vertices.push_back(vec3(1,0,0)+ pos);
        vertices.push_back(vec3(0,1,0)+ pos);
        vertices.push_back(vec3(1,0,0)+ pos);
        vertices.push_back(vec3(1,1,0)+ pos);
    }
       
    //top
    if((pos[1] == (height - 1)) || (volume[(pos[0] + (pos[1]+1)*width + pos[2]*width*height)*4 + 3] == 0)){
        vertices.push_back(vec3(0,1,1)+ pos);
        vertices.push_back(vec3(1,0,1)+ pos);
        vertices.push_back(vec3(1,1,1)+ pos);
        vertices.push_back(vec3(0,0,1)+ pos);
        vertices.push_back(vec3(0,1,1)+ pos);
        vertices.push_back(vec3(1,0,1)+ pos);
    }
    
    //back
    if((pos[2] == 0) || (volume[(pos[0] + pos[1]*width + (pos[2]-1)*width*height)*4 + 3] == 0)){
        vertices.push_back(vec3(0,1,0)+ pos);
        vertices.push_back(vec3(0,1,1)+ pos);
        vertices.push_back(vec3(1,1,1)+ pos);
        vertices.push_back(vec3(1,1,1)+ pos);
        vertices.push_back(vec3(1,1,0)+ pos);
        vertices.push_back(vec3(0,1,0)+ pos);
    }
    
    //front
    if((pos[2] == (depth - 1)) || (volume[(pos[0] + pos[1]*width + (pos[2]+1)*width*height)*4 + 3] == 0)){
        vertices.push_back(vec3(0,0,1)+ pos);
        vertices.push_back(vec3(0,0,0)+ pos);
        vertices.push_back(vec3(1,0,0)+ pos);
        vertices.push_back(vec3(0,0,1)+ pos);
        vertices.push_back(vec3(1,0,0)+ pos);
        vertices.push_back(vec3(1,0,1)+ pos);
    }
     
    //side west
    if((pos[0] == 0) || (volume[((pos[0]-1) + pos[1]*width + pos[2]*width*height)*4 + 3] == 0)){
        vertices.push_back(vec3(0,0,1)+ pos);
        vertices.push_back(vec3(0,0,0)+ pos);
        vertices.push_back(vec3(0,1,0)+ pos);
        vertices.push_back(vec3(0,0,1)+ pos);
        vertices.push_back(vec3(0,1,0)+ pos);
        vertices.push_back(vec3(0,1,1)+ pos);

    }
    
    //side east
    if((pos[0] == (width - 1)) || (volume[((pos[0]+1) + pos[1]*width + pos[2]*width*height)*4 + 3] == 0)){
        vertices.push_back(vec3(1,1,1)+ pos);
        vertices.push_back(vec3(1,0,0)+ pos);
        vertices.push_back(vec3(1,1,0)+ pos);
        vertices.push_back(vec3(1,1,1)+ pos);
        vertices.push_back(vec3(1,0,1)+ pos);
        vertices.push_back(vec3(1,0,0)+ pos);
    }

}

//TODO
//Create a triangulated version of the voxel grid for rendering and populate
//the vertices array.
void VoxelGrid::createMesh(){
    for(int x = 0; x < width; x++){
        for(int y = 0; y < height; y++){
            for(int z = 0; z < depth; z++){
                if(volume[(x + y*width + z*width*height)*4 + 3] != 0){
                    addCube(vec3 (x,y,z));
                    createNormals();
                }
            }
        }
    }
    std::cout << sizeof(vertices) << std::endl;
    std::cout << vertices.size()/sizeof(vertices) << std::endl;
}

//TODO
//Populate the normal array with vertice normals for the triangle mesh
void VoxelGrid::createNormals(){
    
    //bottom
    //if((pos[1] == 0) || (volume[(pos[0] + (pos[1]-1)*width + pos[2]*width*height)*4 + 3] == 0)){
        normals.push_back(vec3(0,0,-1));
        normals.push_back(vec3(0,0,-1));
        normals.push_back(vec3(0,0,-1));
        normals.push_back(vec3(0,0,-1));
        normals.push_back(vec3(0,0,-1));
        normals.push_back(vec3(0,0,-1));
    //}
    
    //top
    //if((pos[1] == (height - 1)) || (volume[(pos[0] + (pos[1]+1)*width + pos[2]*width*height)*4 + 3] == 0)){
        normals.push_back(vec3(0,0,1));
        normals.push_back(vec3(0,0,1));
        normals.push_back(vec3(0,0,1));
        normals.push_back(vec3(0,0,1));
        normals.push_back(vec3(0,0,1));
        normals.push_back(vec3(0,0,1));
    //}
    
    //back
    //if((pos[2] == 0) || (volume[(pos[0] + pos[1]*width + (pos[2]-1)*width*height)*4 + 3] == 0)){
        normals.push_back(vec3(0,1,0));
        normals.push_back(vec3(0,1,0));
        normals.push_back(vec3(0,1,0));
        normals.push_back(vec3(0,1,0));
        normals.push_back(vec3(0,1,0));
        normals.push_back(vec3(0,1,0));
    //}
    
    //front
    //if((pos[2] == (depth - 1)) || (volume[(pos[0] + pos[1]*width + (pos[2]+1)*width*height)*4 + 3] == 0)){
        normals.push_back(vec3(0,-1,0));
        normals.push_back(vec3(0,-1,0));
        normals.push_back(vec3(0,-1,0));
        normals.push_back(vec3(0,-1,0));
        normals.push_back(vec3(0,-1,0));
        normals.push_back(vec3(0,-1,0));
    //}
    
    //side west
    //if((pos[0] == 0) || (volume[((pos[0]-1) + pos[1]*width + pos[2]*width*height)*4 + 3] == 0)){
        normals.push_back(vec3(-1,0,0));
        normals.push_back(vec3(-1,0,0));
        normals.push_back(vec3(-1,0,0));
        normals.push_back(vec3(-1,0,0));
        normals.push_back(vec3(-1,0,0));
        normals.push_back(vec3(-1,0,0));
    //}
    
    //side east
    //if((pos[0] == (width - 1)) || (volume[((pos[0]+1) + pos[1]*width + pos[2]*width*height)*4 + 3] == 0)){
        normals.push_back(vec3(1,0,0));
        normals.push_back(vec3(1,0,0));
        normals.push_back(vec3(1,0,0));
        normals.push_back(vec3(1,0,0));
        normals.push_back(vec3(1,0,0));
        normals.push_back(vec3(1,0,0));
    //}
    
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
                    /*
                    //bottom
                    if((y == 0) || (volume[(x + (y-1)*width + z*width*height)*4 + 3] == 0)){
                        for(int c = 0; c < 6; c++){
                            colors.push_back(vec3(r,g,b));
                        }
                    }
                    
                    //top
                    if((y == (height - 1)) || (volume[(x + (y+1)*width + z*width*height)*4 + 3] == 0)){
                        for(int c = 0; c < 6; c++){
                            colors.push_back(vec3(r,g,b));
                        }
                    }
                    
                    //back
                    if((z == 0) || (volume[(x + y*width + (z-1)*width*height)*4 + 3] == 0)){
                        for(int c = 0; c < 6; c++){
                            colors.push_back(vec3(r,g,b));
                        }
                    }
                    
                    //front
                    if((z == (depth - 1)) || (volume[(x + y*width + (z+1)*width*height)*4 + 3] == 0)){
                        for(int c = 0; c < 6; c++){
                            colors.push_back(vec3(r,g,b));
                        }
                    }
                    
                    //side west
                    if((x == 0) || (volume[((x-1) + y*width + z*width*height)*4 + 3] == 0)){
                        for(int c = 0; c < 6; c++){
                            colors.push_back(vec3(r,g,b));
                        }
                    }
                    
                    //side east
                    if((x == (width - 1)) || (volume[((x+1) + y*width + z*width*height)*4 + 3] == 0)){
                        for(int c = 0; c < 6; c++){
                            colors.push_back(vec3(r,g,b));
                        }
                    }
                     */
                    
                }
            }
        }
    }
}
