# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if head == None:
            return head
        if n == 1 and head.next == None:
            return None
        current = head
        nth = current
        count = 1
        while current.next <> None:
            if count > n:
                nth = nth.next
            current = current.next
            count += 1
        if count == n:
            head = head.next
        else:
            nth.next = nth.next.next
        return head
