open Tape;

open Fetch;

open Js.Promise;

let host = "https://jsonplaceholder.typicode.com";

let getUrl = host ++ "/todos/1";

let postUrl = host ++ "/todos";

let payload = Js.Dict.empty();

Js.Dict.set(payload, "hello", Js.Json.string("world"));

let body = Options.Body.make(Js.Json.object_(payload));

let signal = AbortController.make()->AbortController.signal;

let test = (name, fn) =>
  test(
    name,
    t => {
      t.plan(1);
      fn(() => t.pass("success"));
    },
  );

test("`json` works with url", endTest =>
  json(~url=getUrl, ()) |> then_(_result => endTest() |> resolve) |> ignore
);

test("`json` fails when attempting to use with body", endTest =>
  json(~url=getUrl, ~options=Options.make(~body, ()), ())
  |> catch(_error => endTest() |> Obj.magic)
  |> ignore
);

test("`json` works with url and signal", endTest =>
  json(~url=getUrl, ~options=Options.make(~signal, ()), ())
  |> then_(_result => endTest() |> resolve)
  |> ignore
);

test("`postJSON` works with url", endTest =>
  postJSON(~url=postUrl, ())
  |> then_(_result => endTest() |> resolve)
  |> ignore
);

test("`postJSON` works with url and body", endTest =>
  postJSON(~url=postUrl, ~options=Options.make(~body, ()), ())
  |> then_(_result => endTest() |> resolve)
  |> ignore
);

test("`postJSON` works with url, body and signal", endTest =>
  postJSON(~url=postUrl, ~options=Options.make(~body, ~signal, ()), ())
  |> then_(_result => endTest() |> resolve)
  |> ignore
);

test("`postForm` works with url", endTest =>
  postForm(~url=postUrl, ())
  |> then_(_result => endTest() |> resolve)
  |> ignore
);

test("`postForm` works with url and body", endTest =>
  postForm(~url=postUrl, ~options=Options.make(~body, ()), ())
  |> then_(_result => endTest() |> resolve)
  |> ignore
);

test("`postForm` works with url, body and signal", endTest =>
  postForm(~url=postUrl, ~options=Options.make(~body, ~signal, ()), ())
  |> then_(_result => endTest() |> resolve)
  |> ignore
);
