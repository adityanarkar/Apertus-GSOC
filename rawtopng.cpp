#include "lodepng.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main () {
  char filename[] = "portrait-gainx2-offset2047-20ms-02.raw12";
  char pngflie[] = "output.png";
  std::vector<unsigned char> image;
  std::vector<unsigned char> png, pngcopy;
  unsigned width, height;
  width = 2048;
  height = 1536;
  unsigned e = lodepng::load_file(image, filename);
  std::cout<<image.size()<<'\n';
  std::vector<unsigned char> imgcopy(image.size());
  for(int i = 0; i < image.size(); ++i) {
    if (i%2 != 0) {
      imgcopy[i]= 0xE0 & image[i];
    }
    else {
      imgcopy[i] = (0x0E & image[i]) << 4;
    }
  }
  if (e) std::cout << e << '\n';
  unsigned error = lodepng::encode(png,imgcopy, width, height, LCT_GREY);
  if (error) std::cout << error << '\n';
  unsigned ep = lodepng::save_file(png, pngflie);
  if (ep) std::cout << e << '\n';
  std::cout << png.size() << '\n';
  unsigned ep2 = lodepng::save_file(png, pngflie);
  return 0;
}
