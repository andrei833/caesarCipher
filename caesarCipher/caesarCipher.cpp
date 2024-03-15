#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>


void readDistribution(float* distr) {
	int i = 0;
	char line[20];
	FILE* distribution = fopen("distribution.txt", "r");
	while (fgets(line, sizeof(line), distribution)) {
		distr[i] = atof(line);
		i++;
	}
	fclose(distribution);
}

char myTolower(char s) {
	if (s >= 'A' && s <= 'Z')
		return s + 32;
	return s;
}

void computeFrequency(float* freq, const char* codedMessage)
{
	int i = 0;
	while (codedMessage[i]) {
		char letter = myTolower(codedMessage[i]);
		if (letter >= 'a' && letter <= 'z')
			freq[letter - 'a']++;
		i++;
	}
}

float computeChiSquare(float* distr, float* freq) {
	float distance = 0;
	int i = 0;
	while (i < 26) {
		distance += (freq[i] - distr[i]) * (freq[i] - distr[i]) / distr[i];
		i++;
	}
	return distance;
}

void permuteFreq(float* freq) {
	float hold = freq[25];
	int i = 25;
	while (i > 1)
	{
		freq[i] = freq[i - 1];
		i--;
	}
	freq[0] = hold;
}

int computeOffset(float* distr, float* freq) {
	int offset = 0;
	int finOffset = 0;
	float minDistance = 3.402823466e+38F;
	float distance = 0;
	while (offset < 25)
	{
		distance = computeChiSquare(distr, freq);
		//printf("%f\n", distance);
		if (distance < minDistance) {
			minDistance = distance;
			finOffset = offset;
		}
		permuteFreq(freq);
		offset++;
	}
	return finOffset;
}

char* obtainText(int offset, char* codedMessage) {

	int i = 0;
	while (codedMessage[i] != '\0') {

		if (codedMessage[i] >= 'a' && codedMessage[i] <= 'z')
			codedMessage[i] = 'a' + (codedMessage[i] - 'a' + offset) % 26;
		if (codedMessage[i] >= 'A' && codedMessage[i] <= 'Z')
			codedMessage[i] = 'A' + (codedMessage[i] - 'A' + offset) % 26;
		i++;
	}
	return codedMessage;
}

void displayMenu() {
	printf("Menu:\n");
	printf("1. Decode message\n");
	printf("0. Exit\n");
	printf("Enter your choice:");
}

int main() {
	float distr[26];
	char codedMessage[1000];
	float* freq = (float*)calloc(26, sizeof(float));
	readDistribution(distr);

	char command = 'a';
	while (command != '0') {
		displayMenu();
		scanf("%c", &command);
		switch (command)
		{
		case('1'):
			getchar();
			fgets(codedMessage, 1000, stdin);
			computeFrequency(freq, codedMessage);
			int offset = computeOffset(distr, freq);

			char* result = obtainText(offset, codedMessage);
			printf("%s\n", result);
		}
	}

	free(freq);
	return 0;
}