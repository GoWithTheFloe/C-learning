#include <stdio.h>

int main(void) {

  FILE *image_file;                               /* The file on which to write the image */
  int i, j;

  image_file = fopen("image-file-1.pnm", "wb");   /* Open a file for writing.             */

  fputs("P6\n", image_file);                      /* Write the header, including the      */
                                                  /* so-called magic number P6            */
  fputs("500 500\n", image_file);                 /* Width: 500, Height: 500              */
  fputs("255\n", image_file);                     /* 255 colors per byte.                 */

  for(i = 0; i < 500; i++)              
    for (j = 0; j < 500; j++){
      fputc(255, image_file);                     /* Writing the red byte                 */
      fputc(0, image_file);                       /* Write the green byte                 */ 
      fputc(0, image_file);                       /* Write the blue byte                  */
    }

  fclose(image_file);                             /* Close the file.                      */
  return 0;
}