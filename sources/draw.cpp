#include "../includes/tetripic.hpp"

int writeBMP(BMP_FILE file) {
	int fd;
    unsigned int pixelBytesPerRow;
	unsigned int paddingBytesPerRow;
	unsigned int *sizeOfFileEntry;
	unsigned int *sizeofImage;
	unsigned int *sizeofOfset;
	static unsigned char zeroes[3] = {0,0,0};

    fd = open(file.filename, O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    
    pixelBytesPerRow = file.BMP_FILEINFO.width * sizeof(bmp_pixelcolor); // Latimea randului nostru este de 3 ori mai mare, pentru ca fiecare pixel stocheaza in sine cele 3 culor BGR;
    paddingBytesPerRow = ( 4 - (pixelBytesPerRow % 4)) % 4; // Randul trebuie sa fie multiplu al lui 4

    sizeOfFileEntry = (unsigned int*) &file.BMP_HEADER.bfSize;
    *sizeOfFileEntry = 54 + (pixelBytesPerRow+paddingBytesPerRow)*file.BMP_FILEINFO.height;
	sizeofImage = (unsigned int*) &file.BMP_FILEINFO.biSizeImage;
	*sizeofImage = (pixelBytesPerRow+paddingBytesPerRow)*file.BMP_FILEINFO.height;
	sizeofOfset = (unsigned int*) &file.BMP_HEADER.imageDataOffset;
	*sizeofOfset = 14 + file.BMP_FILEINFO.biSize;

	write(fd, &file.BMP_HEADER, sizeof(file.BMP_HEADER));
    write(fd, &file.BMP_FILEINFO, sizeof(file.BMP_FILEINFO));
     
	for (int row = 0; row < file.BMP_FILEINFO.height; row++) {
		write(fd,file.BMP_COLORS[row],pixelBytesPerRow);
		write(fd,zeroes,paddingBytesPerRow);
	}
	close(fd);
	return 0;
}

int readBMP(const char* filename, BMP_FILE &file) {
	FILE *f;
	unsigned char *buffer;
	unsigned char *prow;
	int i;
	int j;
	int widthx3 = 0;

	f = fopen(filename, "rb");
	
	if(!f)
		return(EXIT_FAILURE);
	
	fread(&file.BMP_HEADER, 1, sizeof(file.BMP_HEADER), f);
	fread(&file.BMP_FILEINFO, 1, sizeof(file.BMP_FILEINFO), f);

	if (file.BMP_HEADER.filetype != 0x4d42)
		return(EXIT_FAILURE);

	file.BMP_COLORS = new bmp_pixelcolor *[file.BMP_FILEINFO.height];
    for(i = 0; i < file.BMP_FILEINFO.height; i++)
        file.BMP_COLORS[i] = new bmp_pixelcolor[file.BMP_FILEINFO.width];

	if (file.BMP_COLORS == NULL) {
		cout << "Memoria nu a fost alocata !!!" << endl;	
		return(EXIT_FAILURE);
	}

	widthx3 = (3 * file.BMP_FILEINFO.width + 3) & (-4);

	buffer = new unsigned char[file.BMP_FILEINFO.height * widthx3];

	fread(buffer, 1, (file.BMP_FILEINFO.height * widthx3), f);

	for (i = file.BMP_FILEINFO.height -1; i >= 0; i--) {
		prow = buffer + i * widthx3;
		for (j = 0; j < file.BMP_FILEINFO.width; j++) {
			file.BMP_COLORS[i][j].B = *prow;
			file.BMP_COLORS[i][j].G = *(prow + 1);
			file.BMP_COLORS[i][j].R = *(prow + 2);
			prow += 3;
		}
	}
	fclose(f);

	delete []buffer;

	return(EXIT_SUCCESS);
}