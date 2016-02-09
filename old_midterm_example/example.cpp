int main() {
    int *BArray = new int[6];
    BArray[0] = 2;
    BArray[1] = 5;
    BArray[2] = 18;
    BArray[3] = 7;
    BArray[4] = 1;
    BArray[5] = 0;

    int i, len;
    int *ptr = BArray;
    int **NewArray;

    len = 0;
    while (*ptr != 0) {
        len++;
        ptr++;
    }

    NewArray = new int *[len];
    for (i = 0; i < len; i++) {
        NewArray[i] = new int[BArray[i]];
    }
}
