#include"railcipher.h"
#define MAX_NUM_SENTENCES 5000
#define MAX_CIPHER_LENGTH (MAX_NUM_SENTENCES * MAX_LINE_LENGTH)
#define IN 1
#define OUT 0
//static char** sentences[MAX_NUM_SENTENCES];

int separateLines(char* cipher, char* temp, int k, int startingChar);

void handleDecryption(void) {

	int keys[MAX_KEY_LENGTH];
    char* cipher = (char*)malloc(sizeof(char));
    char* temp[MAX_LINE_LENGTH];
    //char** tableArray;
	int k = -1;
    int nlines , i, nwords;

    //retrieveing key
	k = getKeys(keys);
	if (getchar() != '\n' || k < 1) {
		printf("Error: syntax  of encryption command is not valid!\n");
		return;
	}
	if (!isvalidkey(keys,k)) {
		printf("Error: invalid key! key of length %d must be a permutation of non-negative integers less than %d\n", k, k);
		return;
	}
    //retrieving cipher and storing it dynamically
    cipher = getCipher(cipher, MAX_CIPHER_LENGTH);
    nwords = wordCount(cipher);
    nlines = nwords / k;

    int nchars = separateLines(cipher, temp, k, 0);
    printf("nchars: %d and temp: %s",nchars, temp);
    nchars = separateLines(cipher, temp, k, nchars);
    printf("nchars: %d and temp: %s",nchars, temp);
    //printf("line #%d is: %s", i, temp);

    //tableArray[i] = (char**)malloc(sizeof(char*));

    

    //breaking cipher into lines
	// while (1) {
	// 	temp = getLine(line, MAX_LINE_LENGTH);
	// 	if (i == MAX_NUM_SENTENCES)
	// 		break;
	// 	nwords = wordCount(line);
	// 	if (!nwords) {
	// 		i--;
	// 		if (temp == EOF)
	// 			break;
	// 		continue;
	// 	}
	// 	if (maxwords < nwords)
	// 		maxwords = nwords;
	// 	nwordsArray[i] = nwords;
	// 	sentences[i] = (char**)malloc(nwords * sizeof(char*));
	// 	tokenize(line, sentences[i++]);
	// 	if (temp == EOF)
	// 		break;
	// }
	// nlines = i;
	// if (k < maxwords) {
	// 	printf("Error: the given key is too short for this plaintext.\nThe minimum key length must be %d\n", maxwords);
	// 	return;
	// }
	// printf("\nThe encrypted text is:\n");
	// for (i = 0; i < k;i++)
	// 	for (j = 0; j < nlines;j++)
	// 		printf("%s ", (keys[i] < nwordsArray[j]) ? sentences[j][keys[i]] : "null");
	// printf("\n");

}

char* getCipher(char* cipher, int maxLine) {
    char i, c;
	for (i = 0; i < i < maxLine && (c = getchar()) != EOF; i++){
        //resizing cipher array dynamically
        cipher = (char*)realloc(cipher, (i+1) * sizeof(char));
        cipher[i] = c;
    }
	cipher[i] = '\0';//end of string sign
	return cipher;
}

// char getLine(char* line, int maxLength) {
// 	char lastCharacter;
// 	int i;
// 	for (i = 0; i < maxLength - 1 && (line[i] = getchar()) != '\n' && line[i] != EOF; i++);
// 	lastCharacter = line[i++];
// 	line[i] = '\0';//end of string sign
// 	return lastCharacter;
// }

int separateLines(char* cipher, char* temp, int k, int startingChar) {
	int state = OUT, i = startingChar, count = 0, currentLine = 0;
	while (cipher[i])
		if (!isspace(cipher[i++])) {
			if (state == OUT) {
				count++;
				state = IN;
                if (count > k){
                    count = 0;
                    int j;
                    for (j = startingChar; j < i; j++)
                        temp[j] = cipher[j];
                    temp[++j] = '\0';
                    break;
                }
			}
		}
		else
			state = OUT;
    return i;
}