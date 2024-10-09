*******************************************Image Filters*******************************************

In today's world, image filters are used everywhere to filter and modify our pictures, in photography, social media pltaforms, etcetra. 

An image is nothing but a collection (or a grid) of pixels, each one of which, is a different colour in an image. The files that store images, such as, .jpeg, .jpg pr .bmp, use
24-bits per pixel because each pixel comprises of R, G and B values (the 3 primary colours). Each of the 3 colours is represented by 8 bits in hexadecimal in a pixel 
and hence, 24 bits in binary (or 6 bits, in hexadecimal) per pixel. 

In this file, we implement four filters:
1) Grayscale filter: converts a colourful image to grayscale by modifying each pixel.
2) Reflection filter: which flips the image horizontally.
3) Blur filter: blurs the pixels in a given image.
4) Edge detection: this is used widely in AI or in Instagarm filters to detect edges of an object in image or a video.
   We use "Sobel Operator" to calculate and implement edge detection in an image.

   The filters were tested together on different images, and performed correctly🥇
