# Profile

## Linux

### perf

Set `-fno-omit-frame-pointer` for best results.

```sh
perf record -g path/to/exe
perf report -g 'graph,0.5,caller'
```
