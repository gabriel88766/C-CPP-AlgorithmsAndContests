private class Greater{
    var a:Int = 0
    var b:Int = 0
    fun insert(c: Int){
        if(c > a){
            b = a
            a = c
        }else if(c > b){
            b = c
        }
    }
    fun compare(c: Int): Boolean{
        return c < b
    }
}
fun main(){
    val n = readln().toInt()
    val listnum = readln().split(" ").map { it.toInt() }
    val gr = Greater()
    var c = 0
    for(i in 1..n){
        if(gr.compare(listnum[i-1])){
            c++
        }
        gr.insert(listnum[i-1])
    }
    println(c)
}