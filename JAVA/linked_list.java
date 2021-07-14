/*

Methods implemented:

    public  T       head()
    public  void    addBeginning(T value)
    public  void    addEnd(T value)
    public  void    deleteBeginning()
    public  void    deleteEnd()
    public  int     count()
    public  void    reverse()


*/


package JAVA;

class Node<T>                   	   
{
    private T data;
    private Node<T> next;

    Node()
    {
        data = null;
        next = null;
    }
    public T getData()
    {
        return this.data;
    }
    public void setData(T da)
    {
        this.data = da;
    }
    public Node<T> getNext()
    {
        return this.next;
    }
    public void setNext(Node<T> n)
    {
        this.next = n;
    }
}

public class linked_list<T>             
{
    private Node<T> head;

    linked_list()
    {
        head = null;
    } 

    public T head()                                 // Returns the data stored in the first element
    {
        return this.head.getData();
    }

    public void addBeginning(T value)               // Add a node to beginning of the linked list
    {
        Node<T> newnode = new Node<T>();
        newnode.setData(value); 
        if (this.head != null)
        {
            newnode.setNext(this.head);
        }
        this.head = newnode;
    }

    public void addEnd(T value)                     // Add a node to end of the linked list
    {
        Node<T> newnode = new Node<T>();
        newnode.setData(value);
        if(this.head == null)
        {
            this.head = newnode;
        }
        else
        {
            Node<T> temp = new Node<T>();
            temp = this.head;
            while(temp.getNext() != null)
            {
                temp = temp.getNext();
            }
            temp.setNext(newnode);
        }
    }

    public void deleteBeginning()                   // Delete the node at beginning of the linked list
    {
        if(this.head == null)
        {
            System.err.println("Cannot delete: list already empty");
            System.exit(0);
        }
        else
        {
            Node<T> temp = new Node<T>();
            temp = this.head;
            this.head = this.head.getNext();
            temp.setData(null);
            temp.setNext(null);
            temp = null;
        }
    }

    public void deleteEnd()                         // Delete a node at end of he linked list
    {
        if (this.head == null)
        {
            System.err.println("Cannot delete: list already empty");
            System.exit(0);
        }
        else
        {
            if(this.head.getNext() == null)
            {
                this.head.setData(null);
                this.head = null;
            }
            else
            {
                Node<T> temp = new Node<T>();
                temp = this.head;
                while(temp.getNext().getNext() != null)
                {
                    temp = temp.getNext();
                }
                temp.getNext().setData(null);
                temp.setNext(null);
            }  
        }
    }

    public int count()                              // Count the number of nodes in linked list
    {
        int count = 0;
        Node<T> temp = new Node<T>();
        temp = this.head;
        while(temp != null)
        {
            count++;
            temp = temp.getNext();
        }
        return count;
    }

    public void reverse()                           // Reverse the linked list
    {
        if (this.count() == 0)
        {
            System.err.println("Error: Cannot reverse empty list");
            System.exit(0);
        }
        else if(this.count() == 1)
        {
            return;
        }
        else if(this.count() == 2)
        {
            this.head.getNext().setNext(this.head);
            this.head = this.head.getNext();
            this.head.getNext().setNext(null);
        }
        else 
        {
            Node<T> pointer1 = new Node<T>();
            Node<T> pointer2 = new Node<T>();
            Node<T> pointer3 = new Node<T>();
            pointer1 = this.head;
            pointer2 = this.head.getNext();
            pointer3 = pointer2.getNext();
            pointer1.setNext(null);
            while(pointer3 != null)
            {
                pointer2.setNext(pointer1);
                pointer1 = pointer2;
                pointer2 = pointer3;
                pointer3 = pointer3.getNext();
            }
            pointer2.setNext(pointer1);
            this.head = pointer2;
        }
    }

    public String toString()            
    {
        Node<T> temp = new Node<T>();
        temp = this.head;
        if(temp == null)
        {
            return "Empty List";
        }
        String s = "";
        while(temp != null)
        {
            s = s + temp.getData() + " ";
            temp = temp.getNext();
        }
        return s;
    }
}