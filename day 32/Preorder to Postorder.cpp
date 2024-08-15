void findPostOrderUtil(int pre[], int n, int minval,
                       int maxval, int& preIndex)
{
    if (preIndex == n)
        return;

    if (pre[preIndex] < minval || pre[preIndex] > maxval) {
        return;
    }
    int val = pre[preIndex];
    preIndex++;

    findPostOrderUtil(pre, n, minval, val, preIndex);

    findPostOrderUtil(pre, n, val, maxval, preIndex);
 
    cout << val << " ";
}
void findPostOrder(int pre[], int n)
{
    int preIndex = 0;
 findPostOrderUtil(pre, n, INT_MIN, INT_MAX, preIndex);
}
