int findRow(int** matrix, int top, int bot, int rowSize, int colSize, int target) {
    int mid = top + (bot - top)/2;
    if (top < 0 || bot >= rowSize || top > bot)
        return mid;
    // printf("findRow top %d, bot %d, rowSize %d, target %d\n", top, bot, rowSize, target);
    if (matrix[mid][0] > target) {
        return findRow(matrix, top, mid - 1, rowSize, colSize, target);
    } else if (matrix[mid][colSize - 1] < target) {
        return findRow(matrix, mid+1, bot, rowSize, colSize, target);
    }

    return mid;
}

int findCol(int* matrix, int left, int right, int colSize, int target) {
    int mid = left + (right - left)/2;
    // printf("findCol left %d, mid %d, right %d, colSize %d, target %d\n", left, mid, right, colSize, target);
    if (left < 0 || right >= colSize || left > right)
        return mid;
    if (matrix[mid] == target)
        return mid;
    else if (matrix[mid] > target)
        return findCol(matrix, left, mid - 1, colSize, target);
    else if (matrix[mid] < target)
        return findCol(matrix, mid + 1, right, colSize, target);
    
    return mid;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = 0;
    int col = 0;
    
    if (matrixSize == 0 || (*matrixColSize) == 0)
        return false;
    row = findRow(matrix, row, matrixSize - 1, matrixSize, *matrixColSize, target);
    if (row < 0  || row > matrixSize - 1 || target < matrix[row][0] || target > matrix[row][*matrixColSize - 1])
        return false;
    
    col = findCol(matrix[row], col, *matrixColSize - 1, *matrixColSize, target);
    // printf("searchMatrix row %d, col %d, target %d\n", row, col, target);
    return (target == matrix[row][col]);
}
