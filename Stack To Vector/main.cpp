/*Consider the following function:

template <typename T>
std: :vector<T> stackToVector(std: :stack<T> stack, bool reverseItens)
{
    std::vector<T> items(stack.size());

    while (stack.size() > @) {
        T item = stack.top();
        stack.pop();

        if (reverseItems) {
            items.insert(items.begin(), item);
        }
        else {
            items.push_back(item);
        }
    }
    
    return items;
}

Select the computational complexity of the stackToVector function if the reverseItems argument is false:
A. O(1)
B. O(n)
c. O(n*log(n))
D. O(n^2)

Select the computational complexity of the stackToVector function if the reverseItems argument is true:
A. O(1)
B. O(n)
C. O(n*log(n))
D. O(n^2)

*/