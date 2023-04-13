// import visualization libraries {
const { Tracer, Array1DTracer, ChartTracer, LogTracer, Randomize, Layout, VerticalLayout } = require('algorithm-visualizer');
// }

// define tracer variables {
const chart = new ChartTracer();
const tracer = new Array1DTracer();
const logger = new LogTracer();
Layout.setRoot(new VerticalLayout([chart, tracer, logger]));
const D = Randomize.Array1D({ N: 25 });
tracer.set(D);
tracer.chart(chart);
Tracer.delay();
// }

// logger {
logger.println(`vector original = [${D.join(', ')}]`);
// }


function kEsimoDyV(arr, k) {
    Tracer.delay();
  if (arr.length === 0 || k < 1 || k > arr.length) {
    return null;
  }
  if (arr.length === 1){
      return arr[0];
  }
  const pivot_indice = Math.floor(Math.random() * arr.length);
  const pivot = arr[pivot_indice];
  logger.println(`Pivote = ${pivot}`);
   // visualize {
      tracer.select(pivot);
      Tracer.delay();
      tracer.deselect(pivot);
      // }
  let lows = [];
  let highs = [];
  for (let i = 0; i < arr.length; i++) {
    if (i === pivot_indice) {
        continue;
    } else if (arr[i] < pivot) {
        tracer.select(i);
        Tracer.delay();
        lows.push(arr[i]);
    } else {
        tracer.patch(i);
        Tracer.delay();
        highs.push(arr[i]);
    }
}
    for (let i=0; i<arr.length; i++){
        tracer.deselect(i);
        tracer.depatch(i);
    }
    logger.println(`vector menores = [${lows.join(', ')}]`);
    logger.println(`vector mayores = [${highs.join(', ')}]`);

  if (lows.length === k - 1) {
      logger.println(`El pivote era el elemento k-esimo`);
    return pivot;
  } else if (lows.length > k - 1) {
      tracer.set(lows);
        tracer.chart(chart);
        Tracer.delay();
        logger.println(`El elemento k-kesimo es más pequeño que el pivote. Se busca en el vector de menores`);
    return kEsimoDyV(lows, k);
  } else {
      tracer.set(highs);
        tracer.chart(chart);
        Tracer.delay();
        logger.println(`El elemento k-kesimo es más grande que el pivote. Se busca en el vector de mayores`);
    return kEsimoDyV(highs, k-lows.length-1);
  }
}

let k = Math.floor(Math.random() * 25);
logger.println(`Elemento k a buscar = ${k}`);
let kesimo = kEsimoDyV(D, k);
// logger {
logger.println(`Elemento ${k} = ${kesimo}`);
// }