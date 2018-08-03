open Tape;

open Fetch;

open Js.Promise;

let host = "https://jsonplaceholder.typicode.com";

let getUrl = host ++ "/todos/1";

let postUrl = host ++ "/todos";

let payload = Js.Dict.empty();

Js.Dict.set(payload, "hello", Js.Json.string("world"));

let body = Options.Body.make(Js.Json.stringify(Js.Json.object_(payload)));

let signal = AbortController.make() |. AbortController.signal;

test("`json` works with url", t =>
  json(~url=getUrl, ()) |> then_(_result => t.endTest() |> resolve) |> ignore
);

test("`json` fails when attempting to use with body", t =>
  json(~url=getUrl, ~options=Options.make(~body, ()), ())
  |> catch(_error => t.endTest() |> Obj.magic)
  |> ignore
);

test("`json` works with url and signal", t =>
  json(~url=getUrl, ~options=Options.make(~signal, ()), ())
  |> then_(_result => t.endTest() |> resolve)
  |> ignore
);

test("`postJSON` works with url", t =>
  postJSON(~url=postUrl, ()) |> then_(_result => t.endTest() |> resolve) |> ignore
);

test("`postJSON` works with url and body", t =>
  postJSON(~url=postUrl, ~options=Options.make(~body, ()), ())
  |> then_(_result => t.endTest() |> resolve)
  |> ignore
);

test("`postJSON` works with url, body and signal", t =>
  postJSON(~url=postUrl, ~options=Options.make(~body, ~signal, ()), ())
  |> then_(_result => t.endTest() |> resolve)
  |> ignore
);

test("`postForm` works with url", t =>
  postForm(~url=postUrl, ()) |> then_(_result => t.endTest() |> resolve) |> ignore
);

test("`postForm` works with url and body", t =>
  postForm(~url=postUrl, ~options=Options.make(~body, ()), ())
  |> then_(_result => t.endTest() |> resolve)
  |> ignore
);

test("`postForm` works with url, body and signal", t =>
  postForm(~url=postUrl, ~options=Options.make(~body, ~signal, ()), ())
  |> then_(_result => t.endTest() |> resolve)
  |> ignore
);