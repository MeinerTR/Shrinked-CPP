#include <stdio.h>
#include <string.h>

#define bool int
#define True 1
#define False 0

const char *GetSourceCode(const char *Path) {
	const char *Input = "#inc stdio.h string.h\n#def Hello, World 1 0\nfunc main(void) {\n    return int 0\n}";	
return Input;}

unsigned const int GetType(unsigned const char _OF) {
	unsigned const int OF = (int)_OF;
	if (OF == 46) { return 3;
	} else if (OF > 32 && OF < 48) {
		return 2;
	} else if (OF > 57 && OF < 65) {
		return 2;
	} else if (OF > 48 && OF < 58) {
		return 1;
	} else { return 0; }
	// for (int Idx = 33; Idx < 48; Idx++) {
	// 	printf("ASCII[%c]: %d\n", (char)Idx, Idx);
	// }
	// for (int Idx = 58; Idx < 65; Idx++) {
	// 	printf("ASCII[%c]: %d\n", (char)Idx, Idx);
	// }
	// for (int Idx = 48; Idx < 58; Idx++) {
	// 	printf("INT[%c]: %d\n", (char)Idx, Idx);
	// }
}

const unsigned char *Split(const char *Line, unsigned const char BY, unsigned const int TargetIndex) {
	unsigned int CurrIndex = 0, CurrLindex = 0, 
					   			CurrOPos = 0;
	static unsigned char _Line[42]; unsigned char CHR, 
	Operator[2]; 	  memset(_Line, 0, strlen(_Line));
	for (int Idx = 0; Idx < strlen(Line) + 1; Idx++) {
		CHR = Line[Idx]; if (CHR == BY | CHR == '\0') {CurrLindex = 0;
			if (CurrIndex == TargetIndex) {
				printf("BREAK!\n%s\n", _Line);
				break; } else {CurrIndex++;}
		} else { if (CurrIndex == TargetIndex - 1) {
			if ((GetType(CHR)) == 2) {
				if (CurrOPos > 1) {CurrOPos = 0;}
				Operator[CurrOPos] = CHR; CurrOPos += 1;
			} else {_Line[CurrLindex] = CHR; CurrLindex++;}}}
	} return _Line; }

const char *C_ed(const char *Syntax) {
	// ;#inc<lib>:#include<lib>;
}

const unsigned char *ConvertToC(const char *Code) {
	static unsigned
	char C_Code[2048], Line[42];
	unsigned int _C_Code = 0, _Line = 0;
	bool Variable = False; char CHR;
	for (int Idx = 0; Idx < strlen(Code); Idx++) {
		CHR = Code[Idx]; if (CHR == '\n') {
			printf("%s\n", Line); _Line = 0;
			printf("Split('%s'): %s\n", Line, Split(Line, ' ', 2));
			memset(Line, 0, strlen(Line));
		} else {Line[_Line] = CHR; _Line++;}
	}
return C_Code;}

int main() {
	const char *SourceCode = GetSourceCode("/home/EnesBatur/Çöp/Tüm-Videolar/YoutubeTR");
	printf("Output:\n%s\n", ConvertToC(SourceCode));
return 0;}