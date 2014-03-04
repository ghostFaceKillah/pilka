function clearCanvas(ctx) {
  ctx.save();
  ctx.setTransform(1, 0, 0, 1, 0, 0);
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  ctx.restore();
};

function drawDot(ctx, color, dot) {
  if (color == "bleak") {
    ctx.fillStyle = "rgb(150,150,150)"; 
    ctx.fillRect(dot.x,dot.y,1,1);
  }
  if (color == "red") {
    ctx.fillStyle = "rgb(200,0,0)"; 
    ctx.fillRect(dot.x-1,dot.y-1,6,6);
  }

  ctx.fillRect(dot.x,dot.y,4,4);
  ctx.fillStyle = "rgb(0,0,0)"; 
};

function drawLine(ctx, line) {
  ctx.beginPath();
  ctx.moveTo(line.from_x, line.from_y);
  ctx.lineTo(line.to_x, line.to_y);
  ctx.closePath();
  ctx.stroke();
};

function drawFrame(ctx){
    $('#canvas')[0].height/2
      frame(ctx, $('#canvas')[0].width/2, $('#canvas')[0].height/2,  //draw a frame
          $('#canvas')[0].width, $('#canvas')[0].height);
};

function rectangle(ctx, center_x, center_y, sizea, sizeb  ) {
  ctx.beginPath();
  ctx.moveTo(center_x - sizea/2, center_y + sizeb/2);
  ctx.lineTo(center_x + sizea/2, center_y + sizeb/2);
  ctx.lineTo(center_x + sizea/2, center_y - sizeb/2);
  ctx.lineTo(center_x - sizea/2, center_y - sizeb/2);
  ctx.lineTo(center_x - sizea/2, center_y + sizeb/2);
  ctx.closePath();
  ctx.fill();
};

function frame(ctx, center_x, center_y, sizea, sizeb  ) {
  ctx.beginPath();
  ctx.moveTo(center_x - sizea/2, center_y + sizeb/2);
  ctx.lineTo(center_x + sizea/2, center_y + sizeb/2);
  ctx.lineTo(center_x + sizea/2, center_y - sizeb/2);
  ctx.lineTo(center_x - sizea/2, center_y - sizeb/2);
  ctx.lineTo(center_x - sizea/2, center_y + sizeb/2);
  ctx.closePath();
  ctx.stroke();
};

function rotate( x, y, alpha ) {
  newx = Math.cos(alpha)*x - Math.sin(alpha)*y;
  newy = Math.sin(alpha)*x + Math.cos(alpha)*y;
  return [newx,newy];
};


function getKeyboardInput(wind, pressed) {

  $(wind).keydown(function(event){
    if(event.keyCode == 37) {
      event.preventDefault();
      pressed[0] = 1;   // left
    }
    if(event.keyCode == 39) {
      event.preventDefault();
      pressed[3] = 1;   // right
    }
    if(event.keyCode == 38) {
      event.preventDefault();
      pressed[2] = 1;   // up
    }
    if(event.keyCode == 40) {
      event.preventDefault();
      pressed[1] = 1;   // down
    }
  });

  $(wind).keyup(function(event){
    if(event.keyCode == 37) {
      event.preventDefault();
      pressed[0] = 0;   // left
    }
    if(event.keyCode == 39) {
      event.preventDefault();
      pressed[3] = 0;   // right
    }
    if(event.keyCode == 38) {
      event.preventDefault();
      pressed[2] = 0;   // up
    }
    if(event.keyCode == 40) {
      event.preventDefault();
      pressed[1] = 0;   // down
    }
  });

  return pressed;
};
