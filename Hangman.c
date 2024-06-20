#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //check in the end what libraries to remove
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LENGTH 30
#define WORD_COUNT 10000

int getRandomWord(FILE* file, char* randomWord);
void guess(char* word, int length);

int main()
{
	int length;
	srand(time(NULL));
	char* word = (char*)malloc((MAX_WORD_LENGTH + 1) * sizeof(char));

	if (word == NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}

	FILE* file = fopen("C:\\Users\\zorof\\New folder\\Downloads\\google-10000-english-no-swears.txt", "r");
	if (file == NULL) {
		perror("Error opening dictionary file");
		return 1;
	}
	length = getRandomWord(file, word);

	guess(word, length);

	free(word);
	return 1;
}

int getRandomWord(FILE* file, char* randomWord) {
	int randomIndex = rand() % WORD_COUNT;

	for (int i = 0; i < randomIndex; i++) {
		fscanf(file, "%s", randomWord);
	}
	size_t length = strlen(randomWord);
	randomWord[length] = '\0';
	return length;
}

void guess(char* word, int length)
{
	char letter;
	char* newWord = (char*)malloc((length + 1) * sizeof(char));
	if (newWord == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}

	for (int i = 0; i < length; i++)
	{
		newWord[i] = '_';
	}
	newWord[length] = '\0';

	while (strcmp(word, newWord) != 0)
	{
		printf("guess a letter: ");
		scanf(" %c", &letter);
		for (int i = 0; i < length; i++)
		{
			if (word[i] == letter)
			{
				newWord[i] = letter;
			}
		}
		printf("%s\n", newWord);
	}
	printf("congratulations, you have found the mystery word!\n");

	free(newWord);
}