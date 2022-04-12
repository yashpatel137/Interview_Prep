static void insert_at_bottom(char x)
{
    if(st.isEmpty())
        st.push(x);

    else
    {
        char a = st.peek();
        st.pop();
        insert_at_bottom(x);
        st.push(a);
    }
}