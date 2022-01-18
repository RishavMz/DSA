package main

import "fmt"

type Node struct {
	value int
	next  *Node
}

type LinkedList struct {
	head   *Node
	length int
}

func insertHead(list *LinkedList, data int) {
	var newNode = Node{data, nil}
	if list.head == nil {
		list.head = &newNode
	} else {
		newNode.next = list.head
		list.head = &newNode
	}
	list.length++
}

func removeHead(list *LinkedList) {
	if list.head != nil {
		list.head = list.head.next
		list.length--
	}
}

func insertEnd(list *LinkedList, data int) {
	var newNode = Node{data, nil}
	if list.head == nil {
		list.head = &newNode
	}
	var tempNode *Node = list.head
	for tempNode.next != nil {
		tempNode = tempNode.next
	}
	tempNode.next = &newNode
	list.length++
}

func removeEnd(list *LinkedList) {
	var tempNode *Node = list.head
	if list.head == nil || list.head.next == nil {
		list.head = nil
		return
	}
	for tempNode.next.next != nil {
		tempNode = tempNode.next
	}
	tempNode.next = nil
	list.length--
}

func getAt(list *LinkedList, position int) int {
	if position < 0 || position >= list.length {
		return -1
	}
	var tempNode *Node = list.head
	for i := 0; i < position; i++ {
		tempNode = tempNode.next
	}
	return tempNode.value
}

func insertAt(list *LinkedList, data int, position int) {
	if position < 0 {
		return
	}
	var newNode = Node{data, nil}
	var tempNode *Node = list.head
	position--
	for position > 0 && tempNode.next != nil {
		tempNode = tempNode.next
		position--
	}
	newNode.next = tempNode.next
	tempNode.next = &newNode
}

func deleteAt(list *LinkedList, position int) {
	if position < 0 || position >= list.length {
		return
	}
	var tempNode *Node = list.head
	position--
	for position > 0 && tempNode.next != nil {
		tempNode = tempNode.next
		position--
	}
	tempNode.next = tempNode.next.next
}

func reverse(list *LinkedList) {
	if list.head == nil || list.head.next == nil {
		return
	} else if list.head.next.next == nil {
		list.head.next.next = list.head
		list.head = list.head.next
		list.head.next.next = nil
	} else {
		var ptr1 *Node = list.head
		var ptr2 *Node = ptr1.next
		var ptr3 *Node = ptr2.next
		ptr1.next = nil
		for ptr3 != nil {
			ptr2.next = ptr1
			ptr1 = ptr2
			ptr2 = ptr3
			ptr3 = ptr3.next
		}
		ptr2.next = ptr1
		list.head = ptr2
	}
}

func print(list *LinkedList) {
	var tempNode *Node = list.head
	for tempNode != nil {
		fmt.Print(tempNode.value)
		tempNode = tempNode.next
	}
	fmt.Println()
}
