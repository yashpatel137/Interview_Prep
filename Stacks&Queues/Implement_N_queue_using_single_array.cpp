class NQueue
{
    // Array to implement the queues.
    vector<int> arr;

    // Array to keep track of the indices of the front elements of every queue.
    vector<int> start;

    // Array to keep track of the indices of the rear elements of every queue.
    vector<int> end;

    // Array to store the next pointers/indices.
    vector<int> next;

    int n, s;

    // Variable to store the starting index of the empty list.
    int temp;

public:
    // Initialize your data structure.
    NQueue(int N, int S)
    {
        n = N;
        s = S;

        // Create the arrays.
        arr = vector<int>(s);
        start = vector<int>(n);
        end = vector<int>(n);
        next = vector<int>(s);

        // Initialize all queues as empty.
        for (int i = 0; i < n; i++)
        {
            start[i] = -1;
            end[i] = -1;
        }

        // Initialize all spaces as empty as initially the complete array is empty.
        for (int i = 0; i < s - 1; i++)
        {
            next[i] = i + 1;
        }

        // Set the last pointer of the empty list to -1 to indicate the end of empty list.
        next[s - 1] = -1;

        // Initialize the starting index of the empty list.
        temp = 0;
    }

    // Enqueues 'X' into the Mth Queue. Returns true if it gets enqueued into the queue, and false otherwise.
    bool enqueue(int x, int m)
    {
        if (temp == -1)
        {
            // Array is full. So, element cannot be inserted.
            return false;
        }

        // Store the index of the first empty slot in a temporary variable.
        int index = temp;

        // Update the starting index of the empty list.
        temp = next[index];

        // Check if queue is empty.
        if (start[m - 1] == -1)
        {
            
            // Update start array.
            start[m - 1] = index;
        }
        else
        {

            // Update next element of end.
            next[end[m - 1]] = index;
        }

        // Update next element.
        next[index] = -1;

        // Update end element for the given queue.
        end[m - 1] = index;

        // Put the value to be enqueued into the array.
        arr[index] = x;
        return true;
    }

    // Dequeues top element from Mth Queue. Returns -1 if the queue is empty, otherwise returns the dequeued element.
    int dequeue(int m)
    {
        if (start[m - 1] == -1)
        {
            // Queue is empty. So, return -1.
            return -1;
        }

        // Find the index of the front element of the queue.
        int index = start[m - 1];

        // Remove the element from the queue by updating the front of the stack list.
        start[m - 1] = next[index];

        // Add the empty slot to the empty list.
        next[index] = temp;
        temp = index;

        // Return the popped element.
        return arr[index];
    }
};