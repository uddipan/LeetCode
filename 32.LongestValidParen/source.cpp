int longestValidParentheses(char* s) {
    int len = strlen(s);
    int *stack = (int*)malloc(sizeof(int)*len);
    int top = -1;
    stack[++top] = -1;
    int max = 0;
    for(int i = 0; i < len; i++)
    {
        int t = stack[top];
        if(t!=-1 && s[i]==')' && s[t]=='(')
        {
            if(i-stack[--top] > max)
                max = i-stack[top];
        }
        else
            stack[++top] = i;
    }
    return max;
}