package main


/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
type ListNode struct {
	Val int
	Next *ListNode
}

func oddEvenList(head *ListNode) *ListNode {
	previous := head
	if previous == nil || previous.Next == nil {
		return head
	}
	current := previous.Next
	previous.Next = current.Next
	current.Next = nil
	evenHead := current
	evenNode := evenHead
	current = previous.Next

	counter := 1
	for ;current != nil;{
		if counter % 2 == 0  {
			tmp := current.Next
			previous.Next = tmp
			evenNode.Next = current
			current.Next = nil
			evenNode = current
			current = tmp

		} else {
			previous=current
			current=current.Next
		}
		counter += 1
	}
	previous.Next = evenHead
	return head
}


func main() {


}
