#include "common.h"
#include "SourcePath.h"


using namespace Angel;

typedef vec4 color4;

// Initialize shader lighting parameters
vec4 light(   0.0, 0.0, 10.0, 1.0 );
color4 light_ambient(  0.1, 0.1, 0.1, 1.0 );
color4 light_diffuse(  1.0, 1.0, 1.0, 1.0 );
color4 light_specular( 1.0, 1.0, 1.0, 1.0 );

// Initialize shader material parameters
color4 material_ambient( 0.1, 0.1, 0.1, 1.0 );
color4 material_diffuse( 0.9, 0.2, 0.3, 1.0 );
color4 material_d2 (0.0, 0.2, 0.9, 1.0);
color4 material_specular( 0.8, 0.8, 0.8, 1.0 );
float  material_shininess = 10;


enum{_EX, _OH, _CRAB, _EMPTY, _MARTINI, _TOTAL_MODELS};
std::string files[_TOTAL_MODELS] = {
                                    "/models/ex.obj",
                                    "/models/oh.obj",
                                    "/models/crab.obj",
                                    "/models/empty.obj",
                                    "/models/martini.obj", };


std::vector < Mesh > mesh;
std::vector < GLuint > buffer;
std::vector < GLuint > vao;
GLuint ModelView_loc, NormalMatrix_loc, Projection_loc, NewModel_loc;
bool wireframe;
bool makeAskew;
bool canReset;
int current_draw;
int double_draw;
int mSlot1, mSlot2, mSlot3, mSlot4, mSlot5, mSlot6, mSlot7, mSlot8, mSlot9, mSlot10, mSlot11, mSlot12, mSlot13, mSlot14, mSlot15, mSlot16, mSlot17, mSlot18, mSlot19, mSlot20, mSlot21, mSlot22, mSlot23, mSlot24, mSlot25, mSlot26, mSlot27;
mat4 slot1 = Translate(-10, -10, -10);
mat4 slot2 = Translate(-10, 0, -10);
mat4 slot3 = Translate(-10, 10, -10);
mat4 slot4 = Translate(0, -10, -10);
mat4 slot5 = Translate(0, 0, -10);
mat4 slot6 = Translate(0, 10, -10);
mat4 slot7 = Translate(10, -10, -10);
mat4 slot8 = Translate(10, 0, -10);
mat4 slot9 = Translate(10, 10, -10);
mat4 slot10 = Translate(-10, -10, 0);
mat4 slot11 = Translate(-10, 0, 0);
mat4 slot12 = Translate(-10, 10, 0);
mat4 slot13 = Translate(0, -10, 0);
mat4 slot14 = Translate(0, 10, 0);
mat4 slot15 = Translate(10, -10, 0);
mat4 slot16 = Translate(10, 0, 0);
mat4 slot17 = Translate(10, 10, 0);
mat4 slot18 = Translate(-10, -10, 10);
mat4 slot19 = Translate(-10, 0, 10);
mat4 slot20 = Translate(-10, 10, 10);
mat4 slot21 = Translate(0, -10, 10);
mat4 slot22 = Translate(0, 0, 10);
mat4 slot23 = Translate(0, 10, 10);
mat4 slot24 = Translate(10, -10, 10);
mat4 slot25 = Translate(10, 0, 10);
mat4 slot26 = Translate(10, 10, 10);

int board[3][3][3] = {0};
int player = 1;
int win = 0;


//board[row][column][board]

void playerMove(int board[3][3][3], int player){
    int x, y, z;
    while(1){
        std::cout << "what is your move (x, y, z, seperated by spaces)?: " << std::endl;
        std::cin >> x >> y >> z;
        if(board[x][y][z] != 0){
            std::cout << "that square is occupied, choose another: " << std::endl;
        } else {
            break;
        }
    }
    board[x][y][z] = player;
    
    if(x == 0 && y == 0 && z == 0){mSlot1 = player - 1;}
    if(x == 1 && y == 0 && z == 0){mSlot2 = player - 1;}
    if(x == 2 && y == 0 && z == 0){mSlot3 = player - 1;}
    if(x == 0 && y == 1 && z == 0){mSlot4 = player - 1;}
    if(x == 1 && y == 1 && z == 0){mSlot5 = player - 1;}
    if(x == 2 && y == 1 && z == 0){mSlot6 = player - 1;}
    if(x == 0 && y == 2 && z == 0){mSlot7 = player - 1;}
    if(x == 1 && y == 2 && z == 0){mSlot8 = player - 1;}
    if(x == 2 && y == 2 && z == 0){mSlot9 = player - 1;}
    if(x == 0 && y == 0 && z == 1){mSlot10 = player - 1;}
    if(x == 1 && y == 0 && z == 1){mSlot11 = player - 1;}
    if(x == 2 && y == 0 && z == 1){mSlot12 = player - 1;}
    if(x == 0 && y == 1 && z == 1){mSlot13 = player - 1;}
    if(x == 1 && y == 1 && z == 1){mSlot14 = player - 1;}
    if(x == 2 && y == 1 && z == 1){mSlot15 = player - 1;}
    if(x == 0 && y == 2 && z == 1){mSlot16 = player - 1;}
    if(x == 1 && y == 2 && z == 1){mSlot17 = player - 1;}
    if(x == 2 && y == 2 && z == 1){mSlot18 = player - 1;}
    if(x == 0 && y == 0 && z == 2){mSlot19 = player - 1;}
    if(x == 1 && y == 0 && z == 2){mSlot20 = player - 1;}
    if(x == 2 && y == 0 && z == 2){mSlot21 = player - 1;}
    if(x == 0 && y == 1 && z == 2){mSlot22 = player - 1;}
    if(x == 1 && y == 1 && z == 2){mSlot23 = player - 1;}
    if(x == 2 && y == 1 && z == 2){mSlot24 = player - 1;}
    if(x == 0 && y == 2 && z == 2){mSlot25 = player - 1;}
    if(x == 1 && y == 2 && z == 2){mSlot26 = player - 1;}
    if(x == 2 && y == 2 && z == 2){mSlot27 = player - 1;}

}

void printBoard(int board[3][3][3]){
    std::cout << "  " << board[0][0][0] << " | " << board[1][0][0] << " | " << board[2][0][0] << std::endl;
    std::cout << "-------------\n";
    std::cout << "  " << board[0][1][0] << " | " << board[1][1][0] << " | " << board[2][1][0] << std::endl;
    std::cout << "-------------\n";
    std::cout << "  " << board[0][2][0] << " | " << board[1][2][0] << " | " << board[2][2][0] << std::endl;
    std::cout << "\n\n";

    std::cout << "  " << board[0][0][1] << " | " << board[1][0][1] << " | " << board[2][0][1] << std::endl;
    std::cout << "-------------\n";
    std::cout << "  " << board[0][1][1] << " | " << board[1][1][1] << " | " << board[2][1][1] << std::endl;
    std::cout << "-------------\n";
    std::cout << "  " << board[0][2][1] << " | " << board[1][2][1] << " | " << board[2][2][1] << std::endl;
    std::cout << "\n\n";

    std::cout << "  " << board[0][0][2] << " | " << board[1][0][2] << " | " << board[2][0][2] << std::endl;
    std::cout << "-------------\n";
    std::cout << "  " << board[0][1][2] << " | " << board[1][1][2] << " | " << board[2][1][2] << std::endl;
    std::cout << "-------------\n";
    std::cout << "  " << board[0][2][2] << " | " << board[1][2][2] << " | " << board[2][2][2] << std::endl;
    std::cout << "\n\n";
}

void boardReset(){
    mSlot1 = mSlot2 = mSlot3 = mSlot4 = mSlot5 = mSlot6 = mSlot7 = mSlot8 = mSlot9 = mSlot10 = mSlot11 = mSlot12 = mSlot13 = mSlot14 = mSlot15 = mSlot16 = mSlot17 = mSlot18 = mSlot19 = mSlot20 = mSlot21 = mSlot22 = mSlot23 = mSlot24 = mSlot25 = mSlot26 = mSlot27 = 3;
    player = 1;
    win = 0;
    for(int x = 0; x < 3; x++){
        for(int y = 0; y < 3; y++){
            for(int z = 0; z < 3; z++){
                board[x][y][z] = 0;
            }
        }
    }
    return;
}

int checkWin(int board[3][3][3]){
    int win = 0;
    int hungBoard = 1;

    for(int x = 0; x < 3; x++){
        //Iterate across
        for(int y = 0; y < 3; y++){
            //Iterate down
            for(int z = 0; z < 3; z++){
                //iterate between boards
                if(board[x][y][z] == 0){
                    hungBoard = 0;
                    goto endloop;
                }
            }
        }
    }
    endloop: ;
    if(hungBoard != 0){
        std::cout << "no more possible moves, hung game." << std::endl;
        boardReset();
        return 0;
    } else {
        hungBoard = 1;
    }
    
    for(int x = 0; x < 3; x++){
        //Iterate across
        for(int y = 0; y < 3; y++){
            //Iterate down
            for(int z = 0; z < 3; z++){
                //Iterate between boards
                if(board[x][y][z] != 0){
                    for(int i = -1; i < 2; i++){
                    //check left / right
                        for(int j = -1; j < 2; j++){
                            //check up / down
                            for(int k = -1; k < 2; k++){
                                //check adjacent boards
                                if(((x+2*i) >= 0 && (x+2*i) < 3) && ((y+2*j) >= 0 && (y+2*j) < 3) && ((z+2*k) >= 0 && (z+2*k) < 3)){
                                    //check that adjacent space is a valid address and that its possible to go two squares in that direction
                                    if(i != 0 || j != 0 || k != 0){
                                        if((board[x][y][z] == board[x+i][y+j][z+k]) && (board[x][y][z] == board[x+2*i][y+2*j][z+2*k])){
                                            //check if adjacent square is the same as this one and the next square in that direction is the same as this one
                                            win = board[x][y][z];
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(win == 2){
        std::cout << "The O player won!\n";
        mSlot1 = mSlot2 = mSlot3 = mSlot4 = mSlot5 = mSlot6 = mSlot7 = mSlot8 = mSlot9 = mSlot10 = mSlot11 = mSlot12 = mSlot13 = mSlot14 = mSlot15 = mSlot16 = mSlot17 = mSlot18 = mSlot19 = mSlot20 = mSlot21 = mSlot22 = mSlot23 = mSlot24 = mSlot25 = mSlot26 = mSlot27 = 4;
        canReset = true;
        //boardReset();
    }
    if(win == 1){
        std::cout << "The X player won!\n";
        mSlot1 = mSlot2 = mSlot3 = mSlot4 = mSlot5 = mSlot6 = mSlot7 = mSlot8 = mSlot9 = mSlot10 = mSlot11 = mSlot12 = mSlot13 = mSlot14 = mSlot15 = mSlot16 = mSlot17 = mSlot18 = mSlot19 = mSlot20 = mSlot21 = mSlot22 = mSlot23 = mSlot24 = mSlot25 = mSlot26 = mSlot27 = 2;
        canReset = true;
        //boardReset();
    }
    return win;
}



//==========Trackball Variables==========
static float curquat[4],lastquat[4];
/* current transformation matrix */
static float curmat[4][4];
mat4 curmat_a;
/* actual operation  */
bool scaling;
bool moving;
bool panning;

bool selecting;
/* starting "moving" coordinates */
static int beginx, beginy;
/* ortho */
float ortho_x, ortho_y;
/* current scale factor */
static float scalefactor;
bool lbutton_down;


static void error_callback(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

//User interaction handler
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){

  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
  if (key == GLFW_KEY_SPACE && action == GLFW_PRESS){
      if (canReset == true) {
          boardReset();
      }
  }
  //if (key == GLFW_KEY_P && action == GLFW_PRESS) {

 //      mSlot14 = (mSlot14 +1)%_TOTAL_MODELS;
 // }
  if (key == GLFW_KEY_Q && action == GLFW_PRESS){
      if (mSlot3 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot3 = player - 1;
          board[0][0][0] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_W && action == GLFW_PRESS) {
      if (mSlot6 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot6 = player - 1;
          board[1][0][0] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_E && action == GLFW_PRESS) {
      if (mSlot9 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot9 = player - 1;
          board[2][0][0] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_A && action == GLFW_PRESS) {
      if (mSlot12 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot12 = player - 1;
          board[0][1][0] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_S && action == GLFW_PRESS) {
      if (mSlot15 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot15 = player - 1;
          board[1][1][0] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_D && action == GLFW_PRESS) {
      if (mSlot18 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot18 = player - 1;
          board[2][1][0] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_Z && action == GLFW_PRESS) {
      if (mSlot21 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot21 = player - 1;
          board[0][2][0] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_X && action == GLFW_PRESS) {
      if (mSlot24 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot24 = player - 1;
          board[1][2][0] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_C && action == GLFW_PRESS) {
      if (mSlot27 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot27 = player - 1;
          board[2][2][0] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_R && action == GLFW_PRESS) {
      if (mSlot2 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot2 = player - 1;
          board[0][0][1] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_T && action == GLFW_PRESS) {
      if (mSlot5 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot5 = player - 1;
          board[1][0][1] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_Y && action == GLFW_PRESS) {
      if (mSlot8 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot8 = player - 1;
          board[2][0][1] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_F && action == GLFW_PRESS) {
      if (mSlot11 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot11 = player - 1;
          board[0][1][1] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_G && action == GLFW_PRESS) {
      if (mSlot14 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot14 = player - 1;
          board[1][1][1] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_H && action == GLFW_PRESS) {
      if (mSlot17 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot17 = player - 1;
          board[2][1][1] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_V && action == GLFW_PRESS) {
      if (mSlot20 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot20 = player - 1;
          board[0][2][1] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_B && action == GLFW_PRESS) {
      if (mSlot23 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot23 = player - 1;
          board[1][2][1] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_N && action == GLFW_PRESS) {
      if (mSlot26 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot26 = player - 1;
          board[2][2][1] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_U && action == GLFW_PRESS) {
      if (mSlot1 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot1 = player - 1;
          board[0][0][2] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_I && action == GLFW_PRESS) {
      if (mSlot4 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot4 = player - 1;
          board[1][0][2] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_O && action == GLFW_PRESS) {
      if (mSlot7 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot7 = player - 1;
          board[2][0][2] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_J && action == GLFW_PRESS) {
      if (mSlot10 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot10 = player - 1;
          board[0][1][2] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_K && action == GLFW_PRESS) {
      if (mSlot13 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot13 = player - 1;
          board[1][1][2] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_L && action == GLFW_PRESS) {
      if (mSlot16 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot16 = player - 1;
          board[2][1][2] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_M && action == GLFW_PRESS) {
      if (mSlot19 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot19 = player - 1;
          board[0][2][2] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_COMMA && action == GLFW_PRESS) {
      if (mSlot22 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot22 = player - 1;
          board[1][2][2] = player;
          win = checkWin(board);
      }
  }
  if (key == GLFW_KEY_PERIOD && action == GLFW_PRESS) {
      if (mSlot25 == 3) {
          if (player == 1) { player = 2; }
          else { player = 1; }
          mSlot25 = player - 1;
          board[2][2][2] = player;
          win = checkWin(board);
      }
  }

}

//User interaction handler
static void mouse_click(GLFWwindow* window, int button, int action, int mods){
  
  if (GLFW_RELEASE == action){
    moving=scaling=panning=selecting=false;
    return;
  }
  
  if( mods & GLFW_MOD_SHIFT){
    scaling=true;
  }else if( mods & GLFW_MOD_ALT ){
    panning=true;
  } else if( mods & GLFW_MOD_CONTROL){
      selecting = true;
  }else{
    moving=true;
    trackball(lastquat, 0, 0, 0, 0);
  }
  
  double xpos, ypos;
  glfwGetCursorPos(window, &xpos, &ypos);
  beginx = xpos; beginy = ypos;
}

//User interaction handler
void mouse_move(GLFWwindow* window, double x, double y){
  
  int W, H;
  glfwGetFramebufferSize(window, &W, &H);

  
  float dx=(x-beginx)/(float)W;
  float dy=(beginy-y)/(float)H;
  
  if (panning)
    {
    ortho_x  +=dx;
    ortho_y  +=dy;
    
    beginx = x; beginy = y;
    return;
    }
  else if (scaling)
    {
    scalefactor *= (1.0f+dx);
    
    beginx = x;beginy = y;
    return;
    }
  else if (moving)
    {
    trackball(lastquat,
              (2.0f * beginx - W) / W,
              (H - 2.0f * beginy) / H,
              (2.0f * x - W) / W,
              (H - 2.0f * y) / H
              );
    
    add_quats(lastquat, curquat, curquat);
    build_rotmatrix(curmat, curquat);
    
    beginx = x;beginy = y;
    return;
    }
  else if (selecting){
      std::cout << "selecting\n";

     printBoard(board);
     playerMove(board, player);
     
     win = checkWin(board);
     if(win == 1){
         std::cout << "player 1 won" << std::endl;
         return;
     }
     if(win == 2){
         std::cout << "player 2 won" << std::endl;
         return;
     }

     if (player == 1){
         player = 2;
     } else {
         player = 1;
     }

  }
}


void init(){
  
  std::string vshader = source_path + "/shaders/vshader.glsl";
  std::string fshader = source_path + "/shaders/fshader.glsl";
  
  GLchar* vertex_shader_source = readShaderSource(vshader.c_str());
  GLchar* fragment_shader_source = readShaderSource(fshader.c_str());

  GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, (const GLchar**) &vertex_shader_source, NULL);
  glCompileShader(vertex_shader);
  check_shader_compilation(vshader, vertex_shader);
  
  GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader, 1, (const GLchar**) &fragment_shader_source, NULL);
  glCompileShader(fragment_shader);
  check_shader_compilation(fshader, fragment_shader);
  
  GLuint program = glCreateProgram();
  glAttachShader(program, vertex_shader);
  glAttachShader(program, fragment_shader);
  
  glLinkProgram(program);
  check_program_link(program);
  
  glUseProgram(program);
  
  glBindFragDataLocation(program, 0, "fragColor");

  //Per vertex attributes
  GLuint vPosition = glGetAttribLocation( program, "vPosition" );
  GLuint vNormal = glGetAttribLocation( program, "vNormal" );

  //Compute ambient, diffuse, and specular terms
  color4 ambient_product  = light_ambient * material_ambient;
  color4 diffuse_product  = light_diffuse * material_diffuse;
  color4 diffuse_2_product = light_diffuse * material_d2;
  color4 specular_product = light_specular * material_specular;
  

  //Retrieve and set uniform variables
  glUniform4fv( glGetUniformLocation(program, "Light"), 1, light);
  glUniform4fv( glGetUniformLocation(program, "AmbientProduct"), 1, ambient_product );
  glUniform4fv( glGetUniformLocation(program, "DiffuseProduct"), 1, diffuse_product );
  glUniform4fv( glGetUniformLocation(program, "SpecularProduct"), 1, specular_product );
  glUniform1f(  glGetUniformLocation(program, "Shininess"), material_shininess );
  
  //Matrix uniform variable locations
  ModelView_loc = glGetUniformLocation( program, "ModelView" );
  NormalMatrix_loc = glGetUniformLocation( program, "NormalMatrix" );
  Projection_loc = glGetUniformLocation( program, "Projection" );
  //NewModel_loc = glGetUniformLocation(program, "ModelView");
  //===== Send data to GPU ======
  vao.resize(_TOTAL_MODELS);
  glGenVertexArrays( _TOTAL_MODELS, &vao[0] );
  
  buffer.resize(_TOTAL_MODELS);
  glGenBuffers( _TOTAL_MODELS, &buffer[0] );
  
  for(unsigned int i=0; i < _TOTAL_MODELS; i++){
  //  if( i == _DRAGON){
     // mesh.push_back(Mesh((source_path + files[i]).c_str(), RotateX(-90)));
   // }else{
      mesh.push_back(Mesh((source_path + files[i]).c_str()));
  //  }

    glBindVertexArray( vao[i] );
    glBindBuffer( GL_ARRAY_BUFFER, buffer[i] );
    unsigned int vertices_bytes = mesh[i].vertices.size()*sizeof(vec4);
    unsigned int normals_bytes  = mesh[i].normals.size()*sizeof(vec3);
    
    glBufferData( GL_ARRAY_BUFFER, vertices_bytes + normals_bytes, NULL, GL_STATIC_DRAW );
    unsigned int offset = 0;
    glBufferSubData( GL_ARRAY_BUFFER, offset, vertices_bytes, &mesh[i].vertices[0] );
    offset += vertices_bytes;
    glBufferSubData( GL_ARRAY_BUFFER, offset, normals_bytes,  &mesh[i].normals[0] );
    
    glEnableVertexAttribArray( vNormal );
    glEnableVertexAttribArray( vPosition );

    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0) );
    glVertexAttribPointer( vNormal, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(mesh[i].vertices.size()*sizeof(vec4)) );

  }
  
  //===== End: Send data to GPU ======


  // ====== Enable some opengl capabilitions ======
  glEnable( GL_DEPTH_TEST );
  glShadeModel(GL_SMOOTH);

  glClearColor( 0.8, 0.8, 1.0, 1.0 );
  
  //===== Initalize some program state variables ======

  //Quaternion trackball variables, you can ignore
  scaling  = 0;
  moving   = 0;
  panning  = 0;
  beginx   = 0;
  beginy   = 0;
    selecting = 0;
  
  matident(curmat);
  trackball(curquat , 0.0f, 0.0f, 0.0f, 0.0f);
  trackball(lastquat, 0.0f, 0.0f, 0.0f, 0.0f);
  add_quats(lastquat, curquat, curquat);
  build_rotmatrix(curmat, curquat);
  
  scalefactor = 1.0;
  makeAskew = false;
  wireframe = false;
  canReset = false;
  current_draw = 0;
  double_draw = 1;
  mSlot1 = 3; mSlot2 = 3; mSlot3 = 3; mSlot4 = 3; mSlot5 = 3; mSlot6 = 3; mSlot7 = 3; mSlot8 = 3; mSlot9 = 3; mSlot10 = 3; mSlot11 = 3; mSlot12 = 3; mSlot13 = 3; mSlot14 = 3; mSlot15 = 3; mSlot16 = 3; mSlot17 = 3; mSlot18 = 3; mSlot19 = 3; mSlot20 = 3; mSlot21 = 3; mSlot22 = 3; mSlot23 = 3; mSlot24 = 3; mSlot25 = 3; mSlot26 = 3; mSlot27 = 3;
  
  lbutton_down = false;


  //===== End: Initalize some program state variables ======

}


int main(void){
  
  GLFWwindow* window;
  
  glfwSetErrorCallback(error_callback);
  
  if (!glfwInit())
    exit(EXIT_FAILURE);
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  glfwWindowHint(GLFW_SAMPLES, 4);
  
  window = glfwCreateWindow(700, 700, "TIC TAC ATTACK", NULL, NULL);
  if (!window){
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  
  //Set key and mouse callback functions
  glfwSetKeyCallback(window, key_callback);
  glfwSetMouseButtonCallback(window, mouse_click);
  glfwSetCursorPosCallback(window, mouse_move);

  
  glfwMakeContextCurrent(window);
  gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
  glfwSwapInterval(1);
  
  init();
  

  
  while (!glfwWindowShouldClose(window)){
    
    //Display as wirfram, boolean tied to keystoke 'w'
    if(wireframe){
      glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    }else{
      glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    }
    
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    
    GLfloat aspect = GLfloat(width)/height;
    
    //Projection matrix
    mat4  projection = Perspective( 45.0, aspect, 0.5, 13.0 );
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //"Camera" position
    const vec3 viewer_pos( 0.0, 0.0, 8.0 );
    
    //Track_ball rotation matrix
    mat4 track_ball =  mat4(curmat[0][0], curmat[1][0], curmat[2][0], curmat[3][0],
                            curmat[0][1], curmat[1][1], curmat[2][1], curmat[3][1],
                            curmat[0][2], curmat[1][2], curmat[2][2], curmat[3][2],
                            curmat[0][3], curmat[1][3], curmat[2][3], curmat[3][3]);
 
    //Modelview based on user interaction
    mat4 user_MV  =  Translate( -viewer_pos ) *                    //Move Camera Back to -viewer_pos
                     Translate(ortho_x, ortho_y, 0.0) *            //Pan Camera
                     track_ball *                                  //Rotate Camera
                     Scale(scalefactor,scalefactor,scalefactor);   //User Scale
    

    // ====== Draw ======
    glBindVertexArray(vao[mSlot14]);
    //glBindBuffer( GL_ARRAY_BUFFER, buffer[current_draw] );
    
    glUniformMatrix4fv( ModelView_loc, 1, GL_TRUE, user_MV*mesh[mSlot14].model_view);
    glUniformMatrix4fv( Projection_loc, 1, GL_TRUE, projection );
    glUniformMatrix4fv( NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV*mesh[mSlot14].model_view)));

    glDrawArrays( GL_TRIANGLES, 0, mesh[mSlot14].vertices.size() );
    // ====== End: Draw ======

 //slot 1
            //mesh.push_back(Mesh((source_path + files[double_draw]).c_str(), Translate(1, 1, -2) * RotateX(-90)));
            glBindVertexArray(vao[mSlot1]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV * mesh[mSlot1].model_view * slot1);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV * mesh[mSlot1].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot1].vertices.size());
//slot 2
                        //mesh.push_back(Mesh((source_path + files[double_draw]).c_str(), Translate(1, 1, -2) * RotateX(-90)));
            glBindVertexArray(vao[mSlot2]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV * mesh[mSlot2].model_view * slot2);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV * mesh[mSlot2].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot2].vertices.size());
//slot3
            glBindVertexArray(vao[mSlot3]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV * mesh[mSlot3].model_view * slot3);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV * mesh[mSlot3].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot3].vertices.size());

            //slot4
            glBindVertexArray(vao[mSlot4]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV * mesh[mSlot4].model_view * slot4);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV * mesh[mSlot4].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot4].vertices.size());
            //slot5
            glBindVertexArray(vao[mSlot5]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot5].model_view* slot5);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot5].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot5].vertices.size());
            //slot6
            glBindVertexArray(vao[mSlot6]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV * mesh[mSlot6].model_view * slot6);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV * mesh[mSlot6].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot6].vertices.size());
            //slot7
            glBindVertexArray(vao[mSlot7]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV * mesh[mSlot7].model_view * slot7);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV * mesh[mSlot7].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot7].vertices.size());
            //slot8
            glBindVertexArray(vao[mSlot8]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot8].model_view* slot8);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot8].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot8].vertices.size());
            //slot9
            glBindVertexArray(vao[mSlot9]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot9].model_view* slot9);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot9].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot9].vertices.size());

            //slot10
            glBindVertexArray(vao[mSlot10]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot10].model_view* slot10);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot10].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot10].vertices.size());

            //slot11
            glBindVertexArray(vao[mSlot11]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot11].model_view* slot11);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot11].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot11].vertices.size());

            //slot12
            glBindVertexArray(vao[mSlot12]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot12].model_view* slot12);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot12].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot12].vertices.size());

            //slot13
            glBindVertexArray(vao[mSlot13]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot13].model_view* slot13);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot13].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot13].vertices.size());

            //slot14
            glBindVertexArray(vao[mSlot15]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot15].model_view* slot14);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot15].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot15].vertices.size());

            //slot15
            glBindVertexArray(vao[mSlot16]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot16].model_view* slot15);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot16].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot16].vertices.size());

            //slot16
            glBindVertexArray(vao[mSlot17]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot17].model_view* slot16);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot17].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot17].vertices.size());

            //slot17
            glBindVertexArray(vao[mSlot18]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot18].model_view* slot17);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot18].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot18].vertices.size());

            //slot18
            glBindVertexArray(vao[mSlot19]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot19].model_view* slot18);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot19].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot19].vertices.size());

            //slot19
            glBindVertexArray(vao[mSlot20]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot20].model_view* slot19);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot20].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot20].vertices.size());


            //slot20
            glBindVertexArray(vao[mSlot21]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot21].model_view* slot20);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot21].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot21].vertices.size());

            //slot21
            glBindVertexArray(vao[mSlot22]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot22].model_view* slot21);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot22].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot22].vertices.size());

            //slot22
            glBindVertexArray(vao[mSlot23]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot23].model_view* slot22);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot23].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot23].vertices.size());

            //slot23
            glBindVertexArray(vao[mSlot24]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot24].model_view* slot23);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot24].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot24].vertices.size());

            //slot24
            glBindVertexArray(vao[mSlot25]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot25].model_view* slot24);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot25].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot25].vertices.size());

            //slot25
            glBindVertexArray(vao[mSlot26]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot26].model_view* slot25);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot26].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot26].vertices.size());

            //slot26
            glBindVertexArray(vao[mSlot27]);
            //glBindBuffer( GL_ARRAY_BUFFER, buffer[double_draw] );
            glUniformMatrix4fv(ModelView_loc, 1, GL_TRUE, user_MV* mesh[mSlot27].model_view* slot26);
            glUniformMatrix4fv(Projection_loc, 1, GL_TRUE, projection);
            glUniformMatrix4fv(NormalMatrix_loc, 1, GL_TRUE, transpose(invert(user_MV* mesh[mSlot27].model_view)));

            glDrawArrays(GL_TRIANGLES, 0, mesh[mSlot27].vertices.size());
      
      
            

    
    glfwSwapBuffers(window);
    glfwPollEvents();
      
     
  }
  
  glfwDestroyWindow(window);
  
  glfwTerminate();
  exit(EXIT_SUCCESS);
}

