/*

Methods Implemented:

    public   int     length()
    public   T       at(int pos)
    public   void    add(T value)                    
    public   void    replace(int position, T value)      
    public   void    insert(int position, T value)       
    public   void    removeAt(int position)      
    public   void    remove(T value)    
    public   int     count(T value)
    public   int     indexOf(T value)      
    public   void    clear()              




*/
package JAVA;

@SuppressWarnings("unchecked")  //Prevent warnings due to generics
public class dynamic_array<T>    
{
    private int capacity;
    private int size;
    private T arr[];
    
    dynamic_array()
    {
        capacity = 10;
        arr = (T[]) new Object[capacity];   
        size = 0;
    }
    
    dynamic_array(int cap)
    {
        arr = (T[]) new Object[cap];   
        size = 0;
        capacity = cap;
    }

    public int length()                             // Returns the current size of the array
    {
        return this.size;
    }

    public T at(int pos)                            // Returns the element at a given position in the array
    {
        if((pos < size) && (pos >= 0))
            return arr[pos];
        System.err.println("Error: Trying to access index value which does not exist");
        System.exit(0);
        return arr[0];
    }

    public void add(T value)                        // Add an element to the array
    {
        if (this.size == this.capacity)
        {
            T brr[] = (T[]) new Object[this.capacity*2];
            for(int i=0; i<this.capacity; i++)
            {
                brr[i] = this.arr[i];
            }
            brr[this.size++] = value;
            this.arr = brr;
            this.capacity = this.capacity*2;
        }
        else 
        {
            this.arr[this.size++] = value;
        }
    }

    public void replace(int position, T value)      // Replace array element at a position with another value
    {
        if (position < this.capacity)
        {
            this.arr[position] = value;
        }
        else
        {
            System.err.println("ERROR: Position exceeds current size of array");
            System.exit(0);
        }
    }

    public void insert(int position, T value)       // Insert value in array at a given position
    {
        if (this.size == this.capacity-1)
        {
            T brr[] = (T[]) new Object[this.capacity*2];
            for(int i=0; i<this.capacity; i++)
            {
                brr[i] = this.arr[i];
            }
            this.capacity = this.capacity*2;
            for(int i=this.size; i>=position; i--)
            {
                brr[i+1] = this.arr[i];
            }
            brr[position] = value;
            this.arr = brr;
            this.size++;
        }
        else if (position > this.capacity)
        {
            System.err.println("Error: position exceeds current size of array");
            System.exit(0);
        }
        else
        {
            for(int i=this.size; i>=position; i--)
            {
                this.arr[i+1] = this.arr[i];
            }
            this.arr[position] = value;
            this.size++;
        }
    }

    public void removeAt(int position)              // Remove array element at a given position
    {
        if (position < this.capacity)
        {
            for(int i = position; i<this.size-1; i++)
            {
                this.arr[i] = this.arr[i+1];
            }    
            this.arr[--this.size] = null;
        }
        else 
        {
            System.err.println("Error: Position exceeds current size of the array");
            System.exit(0);
        }
    }

    public void remove(T value)                     // Removes the first occurance of element from the array
    {
        int found = 0 , i = 0;
        for(i=0; i<this.size; i++)
        {
            if(this.arr[i] == value)
            {
                found = 1;
                break;
            }
        }
        if(found == 1)
        {
            for(int j = i; j<this.size; j++)
            {
                this.arr[j] = this.arr[j+1];
            }
            this.arr[--this.size] = null;
        }
        if (found == 0)
        {
            System.err.println("Error: Item to be deleted not present in array");
            System.exit(0);
        }
    }

    public int count(T value)                       // Count number of occurances of an element in array
    {
        int c = 0;
        for(T i : this.arr)
        {
            if(i == value)
                c++;
        }
        return c;
    }
    
    public int indexOf(T value)                     // Returns the first index of element from the array
    {
        for(int i=0; i<= this.size ; i++)
        {
            if(this.arr[i] == value)
            {
                return i;
            }   
        }
        return -1;
    }

    public void clear()                             // Removes all elements from the array
    {
        for(int i=0; i<this.size; i++)
        {
            this.arr[i] = null;
        }
    }

    public String toString()
    {
        if (this.size == 0)
        {
            return "Empty Array";
        }
        else
        {
            String s = "";
            for(T i : this.arr)
            {
                s = s + " "+ (i == null ? "" : i);
            }
            return s;
        }
    }

}
