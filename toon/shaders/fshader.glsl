#version 150

uniform vec4 AmbientProduct;
uniform vec4 DiffuseProduct;
uniform vec4 SpecularProduct;
uniform vec4 Light;
uniform float Shininess;

in vec4 pos;
in vec4 N;

out vec4 fragColor;

void main()
{
/*
   //l
   vec4 L = normalize(Light-pos);

   //v
   vec4 V = normalize(vec4(0,0,0,1)-pos);
   
   //r
   vec4 R = normalize(reflect(-L,N));
  
  //P
  float P = max(dot(N,V), 0.35);

  // Ambient
  vec4 ambient = P * AmbientProduct;
  
  // Diffuse
  float D  = 1.0;
  vec4  diffuse = D * DiffuseProduct;
  
  //Specular
  float S = 0.0;
  vec4  specular = S * SpecularProduct;
  
  fragColor = ambient + diffuse + specular;
  */


   //l
   vec4 L = normalize(Light-pos);

   //v
   vec4 V = normalize(vec4(0,0,0,1)-pos);
   
   //r
   vec4 R = normalize(reflect(-L,N));


  // Ambient
  vec4 ambient = AmbientProduct;
  
  // Diffuse
  float D  = max(dot(L,N), 0.0);
   if (D < 0.2)
    D = 0.0;
    else if (D < 0.5)
    D = 0.2;
    else if (D < 0.8)
    D = 0.5;
    else if (D < 1.0)
    D = 0.8;
    else
    D = 1.0;
  vec4  diffuse = D * DiffuseProduct;
  
  //Specular
  float S = pow(max(dot(V,R), 0.0), Shininess);
    if (S > 0.2)
    S = 0.8;
   else if (S < 0.2)
    S = 0.0;
  vec4  specular = S * SpecularProduct;
  
  fragColor = ambient + diffuse + specular;
       //intensity
  float Intensity;
  Intensity = dot(N,V);
  if (Intensity < 0.35)
      fragColor = vec4 (0.0,0.0,0.0,1);

}

