// Created by Yashu Chhikara on 11th of May 2025

#include <stdio.h>
#define N 20

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void lruLogic(int RefString[], int numRef, int Frames[], int numFrames) {
    int hit = 0, miss = 0, change = 0;
    int frameVSused[2][3] = { {0} };

    // Copy current frames to frameVSused[0]
    for (int i = 0; i < numFrames; i++)
        frameVSused[0][i] = Frames[i];

    printf("Initially the frames are: ");
    for (int i = 0; i < numFrames; i++)
        printf("%3d", Frames[i]);
    printf("\nApplying FIFO PRA:\n");

    for (int i = 0; i < numRef; i++) {
        change = 0;

        // Check for hit or empty slot
        for (int j = 0; j < numFrames; j++) {
            if (Frames[j] == -1) {
                Frames[j] = RefString[i];
                change = 1;
                miss++;
                printf("Page = %d MISS! Current Miss Count:%d\n", RefString[i], miss);
                printf("Current Frame State:\n");
                for (int k = 0; k < numFrames; k++)
                    printf("%3d", Frames[k]);
                printf("\n");
                break;
            } else if (RefString[i] == Frames[j]) {
                change = 1;
                hit++;
                printf("\nPage = %d HIT! Current Hit Count:%d\n", RefString[i], hit);
                printf("Current Frame State:\n");
                for (int k = 0; k < numFrames; k++)
                    printf("%3d", Frames[k]);
                printf("\n");
                break;
            }
        }

        // If neither hit nor empty, perform LRU replacement
        if (!change) {
            for (int z = 0; z < numFrames; z++)
                frameVSused[0][z] = Frames[z];

            miss++;
            printf("\nPage = %d MISS! Current Miss Count:%d\n", RefString[i], miss);
            int replacement = RefString[i];

            // Find last used index for each page in frame
            for (int k = 0; k < numFrames; k++) {
                for (int l = i-1; l >=0; l--) {
                    if (Frames[k] == RefString[l]) {
                        printf(" Frame[%d]=%d last found at index %d in Ref String\n", k, Frames[k], l);
                        frameVSused[1][k] = l;
                        break;
                    }
                }
            }

            // Show frameVSused matrix
            printf("\nThe frameVSLastUsed state is:\n");
            for (int k = 0; k < 2; k++) {
               
                for (int l = 0; l < numFrames; l++)
                    printf("%d\t", frameVSused[k][l]);
                printf("\n");
            }

            // Shift least element to the last to find least recently used
            for (int i = 0; i < numFrames - 1; i++) {
                if (frameVSused[1][i] < frameVSused[1][i + 1]) {
                    swap(&frameVSused[1][i], &frameVSused[1][i + 1]);
                    swap(&frameVSused[0][i], &frameVSused[0][i + 1]);
                }
            }

            // Replace LRU page(last element)
            printf("Page to be evicted is %d\n", frameVSused[0][2]);
            printf("Because it was used at index %d(least recent)\n", frameVSused[1][2]);

            for (int i = 0; i < numFrames; i++) {
                if (Frames[i] == frameVSused[0][2]) {
                    Frames[i] = replacement;
                }
            }

            // Show new frame state
            printf("\nCurrent Frames State:\n");
            for (int k = 0; k < numFrames; k++)
                printf("%3d", Frames[k]);
            printf("\n");
        }
    }
}

int main(void) {
    int RefString[] = {1, 2, 3, 2, 4, 1, 5, 2, 1, 2, 3, 4, 5};
    int numRef = 13;
    int Frames[3] = { -1, -1, -1 };
    int numFrames = 3;
    lruLogic(RefString, numRef, Frames, numFrames);
}
