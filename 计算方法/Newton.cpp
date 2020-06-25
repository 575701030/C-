//  在VC7.1和Dev C++下编译通过
#include  < windows.h >
#include  < cstring >
#include  < complex >
#include  < iostream >
#include  < fstream >
using   namespace  std;

// 设置迭代次数。。。
const  unsigned  int  MAX  =    100 ;

// 设置图片像素，默认取图片大小为 800×600
void  setPixel(LPBYTE lpBits, unsigned  int  x, unsigned  int  y, BYTE r, BYTE g, BYTE b) {
	lpBits  +=  y * 800 * 3   +  x * 3 ;
	* lpBits         =  b;
	* (lpBits + 1 )  =  g;
	* (lpBits + 2 )  =  r;
	return ;
}

// 指定染色规则
template < typename T >
inline T fun(T k) {
	return  (k * 41 ) % 255 ;
}

int  main( int  argc,  char   * argv[]) {
	//  测试complex
	//    complex<double> c1(4.3, 3.0);
	//    complex<double> c2=c1;
	//
	//    for(int j=0; j< 4800; j++){
	//        for(int i=0; i<100; i++){
	//            c2 = (c1*2.0+1.0/(c1*c1))/3.0;
	//            if(c2==c1) break;
	//            c1=c2;
	//        }
	//           c1=complex<double>(4.3, 3.0);
	//    }
	//       cout << j << endl;

	BITMAPFILEHEADER  hdr;
	BITMAPINFOHEADER  bih;
	LPBYTE  lpBits;

	ZeroMemory( & hdr,  sizeof (hdr));
	ZeroMemory( & bih,  sizeof (bih));
	bih.biSize     =      sizeof (bih);
	bih.biWidth     =      800 ;
	bih.biHeight =      600 ;
	bih.biPlanes =     1 ;
	bih.biCompression  =  BI_RGB;
	bih.biBitCount     =   24 ;
	bih.biSizeImage  =   0 ;
	hdr.bfType  =   0x4d42 ;
	hdr.bfSize  =  (DWORD) ( sizeof (BITMAPFILEHEADER)  +
	                         bih.biSize  +   800 * 600 * 3 );
	hdr.bfOffBits  =  (DWORD)( sizeof (BITMAPFILEHEADER)  +
	                           bih.biSize);
	lpBits  =   new  unsigned  char [ 800 * 600 * 3 ];
	memset(lpBits,  0 ,  800 * 600 * 3 );

	// 测试图片写入
	// for(int j=0; j< 600/2; j++)
	// {
	//     for (int i=0; i<800; i++)
	//     {
	//         setPixel(lpBits, i, j, 250, 0, 0);
	//     }
	// }

	complex < double >  c2,c1;
	int  i,j, k;
	for (j = 0 ; j < 600 ; j ++ ) {
		for (i = 0 ; i < 800 ; i ++ ) {
			c1  =  complex < double > (i * 0.01 - 4 , j * 0.01 - 3 );
			// 迭代个点
			for (k = 0 ; k < MAX; k ++ ) {
				c2  =  (c1 * 2.0 + 1.0 / (c1 * c1)) / 3.0 ;
				if (c2 == c1)  break ;
				c1 = c2;
			}
			if (k == MAX) {
				setPixel(lpBits, i, j,  0 ,  0 ,  0 );
			} else   if ( c1.real()  <   0   &&  c1.imag()  >   0 ) {
				setPixel(lpBits, i, j, fun(k),  0 ,  0 );
			} else   if ( c1.real()  <   0   &&  c1.imag()  <   0 ) {
				setPixel(lpBits, i, j,  0 , fun(k),  0 );
			} else {
				setPixel(lpBits, i, j,  0 ,  0 , fun(k));
			}

		}
	}

	// 写入文件
	ofstream  file( " fenxing.bmp " );
	char *  pTmp  =  reinterpret_cast < char *> ( & hdr);
	file.write(pTmp,  sizeof (BITMAPFILEHEADER));
	pTmp  =  reinterpret_cast < char *> ( & bih);
	file.write(pTmp,  sizeof (BITMAPINFOHEADER));
	file.write(reinterpret_cast < char *> (lpBits),  800 * 600 * 3 );

	delete []lpBits;


	return  EXIT_SUCCESS;
}

