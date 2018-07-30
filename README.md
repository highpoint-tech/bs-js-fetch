# bs-js-fetch

[BuckleScript](https://github.com/bloomberg/bucklescript) bindings for Highpoint's [js-fetch](https://github.com/hp-mobile/js-fetch).

### Pre-requisites

- [yarn](https://yarnpkg.com)

### Installation

```sh
yarn add @highpoint/bs-js-fetch 
```

In your `bsconfig.json`, include `"@hightpoint/bs-js-fetch"` in the `bs-dependencies`.



### Usage

```reason
Fetch.json("http://google.com")
|> Js.Promise.then_(result => /* do something with `result` */ );

Fetch.(
  postForm(
    "schedule-builder",
    Options.(make(~body=Body.make("key1=value1&key2=value2"))),
  )
  |> Js.Promise.then_(result => /* do something with `result` */ )
);

Fetch.(
  postJSON(
    "message-center",
    Options.(make(~body=Body.makeWithUrlSearchParams(urlSearchParams))),
  )
  |> Js.Promise.then_(result => /* do something with `result` */ )
);
```