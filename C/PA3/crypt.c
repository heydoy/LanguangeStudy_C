#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef	union{
	int iVal[4];
	char chVal[16];
} TEXT;
typedef union{
	int iVal[2];
	char chVal[8];
} KEY;

TEXT encrypt(TEXT p, KEY k);
TEXT decrypt(TEXT c, KEY k);
TEXT sub(TEXT in, KEY k);
TEXT mix(TEXT in);
TEXT revsub(TEXT in, KEY k);
TEXT revmix(TEXT in);

int main(int argc, char *argv[]){
	int i;
	TEXT plain = {.iVal = {0}}, cipher = {.iVal = {0}};
	KEY key = {.iVal = {0}};
	if(argc != 4){
		printf("Usage: ./crypt [Text] [Key] [Option]\nOption\n1: Encrypt\n2: Decrypt\n");
		exit(0);
	}
	if(!strcmp(argv[3], "1")){
		// Insert source code for inserting values argv[0] and argv[1] to plain and key, respectively...
		if(strlen(argv[1]) != 16 || strlen(argv[2]) != 8)
                exit(0);
            
            	for(i=0; i <16; i++){
                	plain.chVal[i] = argv[1][i];

                	//printf("%x ", plain.chVal[i]);
            	}
            	for(i=0; i< 8; i++){
                	key.chVal[i] = argv[2][i];
            	}


		cipher = encrypt(plain, key);
		for(i=0;i<16;i++)	printf("%.2X", cipher.chVal[i] & 0xFF);
		printf("\n");
	}
	else if(!strcmp(argv[3], "2")){
		// Insert source code for inserting values argv[0] and argv[1] to cipher and key, respectively...
			
		if(strlen(argv[1]) != 32 || strlen(argv[2]) != 8)
                	exit(0);
            	if(!isxdigit(*argv[1]))
                	exit(0);
            
            	for(i=0; i <4; i++){
                	char slice[9];
                
               	 	strncpy(slice, &(argv[1][8*i]), 8 );
                	cipher.iVal[i] = strtol(slice, NULL, 16);
                
                	//printf("%X ", cipher.iVal[i]);
                
            	}
            	for(i=0; i< 8; i++){
                	key.chVal[i] = argv[2][i];
            	}
	

		plain = decrypt(cipher, key);
		for(i=0;i<16;i++)	printf("%c", plain.chVal[i]);
		printf("\n");
	}
	else{
		printf("Usage: ./crypt [Text] [Key] [Option]\nOption\n1: Encrypt\n2: Decrypt\n");
		exit(0);
	}
	return 0;
}

TEXT encrypt(TEXT p, KEY k){
	return mix(sub(p, k));
}

TEXT decrypt(TEXT c, KEY k){
	return revsub(revmix(c), k);
}

TEXT sub(TEXT in, KEY k){
	TEXT out = {.iVal = {0}};
	// Insert source code for substitution here...
	for(int i = 0; i < 16; i++){
        out.chVal[i] = (in.chVal[i] * 23) % 256;
        if(i < 8)
            out.chVal[i] = out.chVal[i] ^ k.chVal[i];
        else
            out.chVal[i] = out.chVal[i] ^ k.chVal[i-8];
	
	}

	return out;
}

TEXT mix(TEXT in){
	TEXT out = {.iVal = {0}};
	// Insert source code for mixing bits here...
	
	int m[4][3] = {0,};
        int l[4][3] = {0,};
    
        // 32비트를 각 11, 10, 11비트씩 쪼개는 과정
        for(int i = 0; i < 4; i++){
            //왼쪽 11비트 : & 0b11111111111000000000000000000000 후 21비트 >> 이동
            m[i][2] = in.iVal[i] & 0xffe00000;
            m[i][2] >>= 21;
            //가운데 10비트 : & 0b00000000000111111111100000000000 후 11비트 >> 이동
            m[i][1] = in.iVal[i] & 0x1ff800;
            m[i][1] >>= 11;
            //오른쪽 11비트 : & 0b00000000000000000000011111111111 후 이동 x
            m[i][0] = in.iVal[i] & 0x7ff;
        }
        
        // 섞는 과정
    	for(int i = 0; i < 4; i ++){
        	l[i][0] = m[(i+1)%4][0];
        	l[i][1] = m[(i+2)%4][1];
        	l[i][2] = m[(i+3)%4][2];
        
    	}
//        l[0][0] = m[1][0];
//        l[0][1] = m[2][1];
//        l[0][2] = m[3][2];
//
//        l[1][0] = m[2][0];
//        l[1][1] = m[3][1];
//        l[1][2] = m[0][2];
//
//        l[2][0] = m[3][0];
//        l[2][1] = m[0][1];
//        l[2][2] = m[1][2];
//
//        l[3][0] = m[0][0];
//        l[3][1] = m[1][1];
//        l[3][2] = m[2][2];
//
        
        // 섞은 비트를 다시 합쳐서 out에 넣는 과정
        for(int i = 0; i < 4; i++){
            l[i][2] <<= 21;
            l[i][1] <<= 11;
            
            out.iVal[i] = l[i][2] + l[i][1] + l[i][0];
            
        }
    
	
	return out;
}

TEXT revsub(TEXT in, KEY k){
	TEXT out = {.iVal = {0}};
	// Insert source code for reverse substitution here...
	
	for(int i = 0; i < 16; i++){
        	if(i < 8)
            		out.chVal[i] = in.chVal[i]^k.chVal[i];
        	else
            		out.chVal[i] = in.chVal[i]^k.chVal[i-8];
        
        	out.chVal[i] = (out.chVal[i] * 167) % 256;
 
    	}

	return out;
}

TEXT revmix(TEXT in){
	TEXT out = {.iVal = {0}};
	// Insert source code for reverse mixing bits here...
	
	int l[4][3] = {0,};
        int m[4][3] = {0,};
        
        char temp;
      
        
        //정렬
        for(int i = 0; i < 4; i++){
            temp = in.chVal[i*4];
            in.chVal[i*4] = in.chVal[i*4+3];
            in.chVal[i*4+3] = temp;

            temp = in.chVal[i*4+1];
            in.chVal[i*4+1] = in.chVal[i*4+2];
            in.chVal[i*4+2] = temp;

        }

        // 32비트를 각 11, 10, 11비트씩 쪼개는 과정
        for(int i = 0; i < 4; i++)
            for(int i = 0; i < 4; i++){

                //왼쪽 11비트 : & 0b11111111111000000000000000000000 후 21비트 >> 이동
                l[i][2] = in.iVal[i] & 0xffe00000;
                l[i][2] >>= 21;
                //가운데 10비트 : & 0b00000000000111111111100000000000 후 11비트 >> 이동
                l[i][1] = in.iVal[i] & 0x1ff800;
                l[i][1] >>= 11;
                //오른쪽 11비트 : & 0b00000000000000000000011111111111 후 이동 x
                l[i][0] = in.iVal[i] & 0x7ff;

            }

        // 섞는 걸 되돌리는 과정
        for(int i = 0; i < 4; i++){
            m[i][0] = l[(i+3)%4][0];
            m[i][1] = l[(i+2)%4][1];
            m[i][2] = l[(i+1)%4][2];
        }
        // 되돌린 비트를 다시 합쳐서 out에 넣기
        
        for(int i = 0; i < 4; i++){
            m[i][2] <<= 21;
            m[i][1] <<= 11;
            out.iVal[i] = m[i][2] + m[i][1] + m[i][0];
            //printf("\n%x\n",out.iVal[i]);

        }
	
	return out;
}
