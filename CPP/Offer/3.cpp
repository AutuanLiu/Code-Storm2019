class Solution
{
  public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> result;
        stack<int> arr;
        ListNode *p = head;
        while (p != NULL)
        {
            arr.push(p->val);
            p = p->next;
        }
        int len = arr.size();
        for (int i = 0; i < len; i++)
        {
            result.push_back(arr.top());
            arr.pop();
        }
        return result;
    }
};

class Solution
{
  public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> value;
        if (head != NULL)
        {
            value.insert(value.begin(), head->val);
            while (head->next != NULL)
            {
                value.insert(value.begin(), head->next->val);
                head = head->next;
            }
        }
        return value;
    }
};

class Solution
{
  public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> v;
        if (head == NULL)
            return v;
        ListNode *temp = head;

        stack<int> s;
        while (1)
        {
            if (temp != NULL)
            {
                s.push(temp->val);
                temp = temp->next;
            }
            else
                break;
        }

        while (!s.empty())
        {
            //   cout<<s.top();
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};

class Solution
{
  public:
    vector<int> printListFromTailToHead(ListNode *head)
    {
        ListNode *p = head, *TEMP = head, *nhead = new ListNode(0);
        while (p != NULL)
        {
            if (nhead->next != NULL)
            {
                TEMP = TEMP->next;
                p->next = nhead->next;
                nhead->next = p;
                p = TEMP;
            }
            else
            {
                nhead->next = p;
                TEMP = TEMP->next;
                p->next = NULL;
                p = TEMP;
            }
        }
        p = nhead->next;
        vector<int> a;
        while (p != NULL)
        {
            a.push_back(p->val);
            p = p->next;
        }
        return a;
    }
};

class Solution
{
  public:
    vector<int> printListFromTailToHead(struct ListNode *head)
    {
        vector<int> vec;
        printListFromTailToHead(head, vec);
        return vec;
    }
    void printListFromTailToHead(struct ListNode *head, vector<int> &vec)
    {
        if (head != nullptr)
        {
            if (head->next != nullptr)
            {
                printListFromTailToHead(head->next, vec);
            }
            vec.push_back(head->val);
        }
    }
};
