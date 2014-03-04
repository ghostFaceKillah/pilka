$(function() { 
  var ctx = $('#canvas')[0].getContext("2d");

  example_dot = {};
  example_dot.x = 3;
  example_dot.y = 3;

  ex = {};
  ex.x = 7;
  ex.y = 12;
  dots = [ example_dot, ex];

  function drawDot(dot) {
    ctx.fillRect(dot.x,dot.y,3,3);
  };
  $.get('data.txt', function(data) { console.log(data) } );


  function resolve() { 

    clearCanvas(ctx);
    for (i in dots) {
      drawDot(dots[i]);
    }
    $('#canvas')[0].height/2
      frame(ctx, $('#canvas')[0].width/2, $('#canvas')[0].height/2,  //draw a frame
          $('#canvas')[0].width, $('#canvas')[0].height);
  };

  var timer = setInterval(function(){ resolve()} , 10) ;
});
