package 백준

import kotlin.math.ceil
import kotlin.math.ln
import kotlin.math.min

private lateinit var arr:IntArray
private lateinit var tree:IntArray
fun main() {
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val (n,m)=br.readLine().split(" ").map { it.toInt() }
    arr=IntArray(n)
    for(i in 0 until n)
        arr[i]=br.readLine().toInt()
    val h = ceil(ln(n.toDouble()) / ln(2.0)).toInt()
    val size= 1 shl h+1
    tree=IntArray(size)
    init(1,0,n-1)
    repeat(m){
        val (start,end)=br.readLine().split(" ").map { it.toInt()-1 }
        bw.write("${query(1,0,n-1,start,end)}\n")
    }
    bw.flush()

}
private fun init(node:Int,start:Int,end:Int){
    if(start==end)
        tree[node]=arr[start]
    else{
        init(node*2,start,(start+end)/2)
        init(node*2+1,(start+end)/2+1,end)
        tree[node]= min(tree[node*2],tree[node*2+1])
    }
}
private fun query(node:Int,start:Int,end:Int,i:Int,j:Int):Int{
    if(i>end || j<start)
        return -1
    if(i<= start && end<=j)
        return tree[node]
    val m1=query(node*2,start,(start+end)/2,i,j)
    val m2=query(node*2+1,(start+end)/2+1,end,i,j)
    return when {
        m1==-1 -> m2
        m2==-1 -> m1
        else -> return min(m1,m2)
    }
}