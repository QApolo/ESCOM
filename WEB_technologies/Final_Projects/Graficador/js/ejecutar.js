var Points = [];
var plot1 = null;
var mapeo = ["Sen(x)","Cos(x)","Tan(x)","Log(x)","e^x"];

$(document).ready(function(){
    $('select').formSelect();
    ejecutar();
});


function ejecutar() {
    Points = [];
    var funcion = document.getElementById("funciones").selectedIndex;
    switch (funcion) {
        case 0://seno
            for (var i=0; i<4*Math.PI; i+=0.1){ 
                Points.push([i, Math.sin(i)]); 
            } 
            break;
        case 1: //coseno
            for (var i=1; i<4*Math.PI; i+=0.1){ 
                    Points.push([i, Math.cos(i)]); 
                } 
            break;
        case 2: //tan
            for (var i=0; i<2*Math.PI; i+=0.1){ 
                    Points.push([i, Math.tan(i)]); 
                } 
            break;
        case 3:
            for (var i=1; i<2*Math.PI; i+=0.1){ 
                    Points.push([i, Math.log10(i)]); 
                } 
            
            break;
        case 4:
            for (var i=0; i<2*Math.PI; i+=0.1){ 
                    Points.push([i, Math.exp(i)]); 
                } 
            break;
    }
    
    plot1 = $.jqplot('chart1', [Points], {  
        series:[{showMarker:false}],
        axes:{
            xaxis:{
            label:'X'
            
            },
            yaxis:{
            label:mapeo[funcion],
            
            }
        },
          cursor: {
            show: true,
            showTooltip: true,
            zoom: true,
            constrainZoomTo: 'x'
        }
    });
    plot1.redraw();

    //skjsk
    
}

