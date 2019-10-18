# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return None
        if head.next == None:
            return head
        result = head.next
        prevHead = ListNode(0)
        prevHead.next = head
        while head <> None and head.next <> None:
            newHead = head.next
            tmpNext = head.next.next
            prevHead.next = newHead
            newHead.next = head
            head.next = tmpNext
            prevHead = head
            head = tmpNext
        return result
