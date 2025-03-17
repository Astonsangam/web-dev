function rightAngledTriangle() {
    let n = document.getElementById("triangleInput").value;
    let result = "";
    for (let i = 1; i <= n; i++) {
        result += "*".repeat(i) + "\n";
    }
    console.log(result)
    document.getElementById("triangleResult").textContent = result;
}
