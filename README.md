# bs-js-fetch

[BuckleScript](https://github.com/bloomberg/bucklescript) bindings for HighPoint's [js-fetch](https://github.com/hp-mobile/js-fetch).

### Pre-requisites

- [yarn](https://yarnpkg.com)

### Installation

```sh
yarn add @highpoint/bs-js-fetch 
```

In your `bsconfig.json`, include `"@highpoint/bs-js-fetch"` in the `bs-dependencies`.



### Usage

```reason
open Fetch;

json(~url="http://google.com", ())
|> Js.Promise.then_(result => /* do something with `result` */ );

let abortController = AbortController.make();

postForm(
  ~url="schedule-builder",
  ~options=Options.(make(~body=Body.make("key1=value1&key2=value2", ~signal=(abortController |> AbortController.signal), ()))),
  ()
)
|> Js.Promise.then_(result => /* do something with `result` */ )

postJSON(
  ~url="message-center",
  ~options=Options.(make(~body=Body.makeWithUrlSearchParams(urlSearchParams), ())),
  ()
)
|> Js.Promise.then_(result => /* do something with `result` */ )
```
