import kotlin.math.max
import kotlin.math.min

fun main(){
    val q: Int = readln().toInt()
    for(i in 1..q){
        val s: String = readln()
        val a: Int = s.split(" ")[0].toInt();
        val b: Int= s.split(" ")[1].toInt();
        println("${min(a,b)-1} 1 ${max(a,b)-min(a,b)+1}")
    }
}