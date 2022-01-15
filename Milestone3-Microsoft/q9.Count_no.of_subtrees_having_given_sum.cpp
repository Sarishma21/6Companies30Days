pair<int, int> subtreeSum(Node* root, int x) {

    if(root == NULL) return {0, 0};

    int count = 0;

    pair<int, int> left = subtreeSum(root->left, x);
    pair<int, int> right = subtreeSum(root->right, x);

    count += left.first;
    count += right.first;

    int sum = left.second + right.second + root->data;

    if(sum == x) {
        ++count;
    }

    return {count, sum};
}

int countSubtreesWithSumX(Node* root, int x)
{
	pair<int, int> result = subtreeSum(root, x);
	return result.first;
}