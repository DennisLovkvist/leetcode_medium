typedef struct ListNode ListNode;
#define max(a, b) ((a) > (b) ? (a) : (b))
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    ListNode *temp = l1;
    int digit_count1 = 0;
    while(temp != NULL)
    {
        digit_count1 ++;
        temp = temp->next;
    }

    temp = l2;
    int digit_count2 = 0;
    while(temp != NULL)
    {
        digit_count2 ++;
        temp = temp->next;
    }

    ListNode *number_big = digit_count1 > digit_count2 ? l1:l2;
    ListNode *number_small = digit_count1 <= digit_count2 ? l1:l2;

    ListNode *result = number_big;
    int result_max_digits = max(digit_count1,digit_count2)+1;

    int digit_place = 0;
    int carry = 0;
    while(digit_place < result_max_digits)
    {
        int sum = number_big->val + carry;

        if (number_small != NULL) 
        {
            sum += number_small->val;
            number_small = number_small->next;
        }
        carry = sum / 10;
        number_big->val = sum % 10;

        if (number_big->next == NULL) 
        {
            break;
        }
        number_big = number_big->next;
        
        digit_place ++;
    }

    if(carry >0)
    {
        number_big->next = malloc(sizeof(ListNode));
        number_big->next->val = carry;
        number_big->next->next = NULL;
    }

    return result;
}