module Connection = {
  type t = {
    .
    "host": string,
    "port": Js.Nullable.t(string),
    "user": string,
    "password": string,
    "database": string,
    "domain": Js.Nullable.t(string),
    "instanceName": Js.Nullable.t(string),
    "debug": Js.Nullable.t(Js.boolean),
    "requestTimeout": Js.Nullable.t(int)
  };
  [@bs.obj]
  external make :
    (
      ~host: string=?,
      ~port: string=?,
      ~user: string=?,
      ~password: string=?,
      ~database: string=?,
      ~domain: string=?,
      ~instanceName: string=?,
      ~debug: Js.boolean=?,
      ~requestTimeout: int=?,
      ~filename: string=?,
      unit
    ) =>
    t =
    "";
};

module Pool = {
  type t = {
    .
    "name": Js.Nullable.t(string),
    "min": Js.Nullable.t(int),
    "max": Js.Nullable.t(int),
    "refreshIdle": Js.Nullable.t(Js.boolean),
    "idleTimeoutMillis": Js.Nullable.t(int),
    "reapIntervalMillis": Js.Nullable.t(int),
    "returnToHead": Js.Nullable.t(Js.boolean),
    "priorityRange": Js.Nullable.t(int),
    "log": Js.Nullable.t(Js.boolean),
    /* generic-pool v3 configs */
    "maxWaitingClients": Js.Nullable.t(int),
    "testOnBorrow": Js.Nullable.t(Js.boolean),
    "acquireTimeoutMillis": Js.Nullable.t(int),
    "fifo": Js.Nullable.t(Js.boolean),
    "autostart": Js.Nullable.t(Js.boolean),
    "evictionRunIntervalMillis": Js.Nullable.t(int),
    "numTestsPerRun": Js.Nullable.t(int),
    "softIdleTimeoutMillis": Js.Nullable.t(int)
  };
  [@bs.obj]
  external make :
    (
      ~name: string=?,
      ~min: int=?,
      ~max: int=?,
      ~refreshIdle: Js.boolean=?,
      ~idleTimeoutMillis: int=?,
      ~reapIntervalMillis: int=?,
      ~returnToHead: Js.boolean=?,
      ~priorityRange: int=?,
      ~log: Js.boolean=?,
      ~maxWaitingClients: int=?,
      ~testOnBorrow: Js.boolean=?,
      ~acquireTimeoutMillis: int=?,
      ~fifo: Js.boolean=?,
      ~autostart: Js.boolean=?,
      ~evictionRunIntervalMillis: int=?,
      ~numTestsPerRun: int=?,
      ~softIdleTimeoutMillis: int=?,
      unit
    ) =>
    t =
    "";
};

module Migrations = {
  type t = {
    .
    "database": Js.Nullable.t(string),
    "directory": Js.Nullable.t(string),
    "extension": Js.Nullable.t(string),
    "tableName": Js.Nullable.t(string),
    "disableTransactions": Js.Nullable.t(bool)
  };
  [@bs.obj]
  external make :
    (
      ~database: string=?,
      ~directory: string=?,
      ~extension: string=?,
      ~tableName: string=?,
      ~disableTransactions: Js.boolean=?,
      unit
    ) =>
    t =
    "";
};

module Db = {
  type t = {
    .
    "driver": string,
    "user": Js.Nullable.t(string),
    "password": Js.Nullable.t(string),
    "host": Js.Nullable.t(string),
    "hosts": Js.Nullable.t(array({. "host": string, "port": Js.Nullable.t(string)})),
    "port": Js.Nullable.t(string),
    "database": Js.Nullable.t(string),
    "filename": Js.Nullable.t(string),
    "native": Js.Nullable.t(Js.boolean),
    "reconnect": Js.Nullable.t(Js.boolean)
  };
};

type seeds = {. "directory": Js.Nullable.t(string)};

type t = {
  .
  "debug": Js.Nullable.t(string),
  "client": Js.Nullable.t(string),
  "dialect": Js.Nullable.t(string),
  "version": Js.Nullable.t(string),
  "connection": Js.Nullable.t(Connection.t),
  "pool": Js.Nullable.t(Pool.t),
  "migrations": Js.Nullable.t(Migrations.t),
  "seeds": Js.Nullable.t(seeds),
  "acquireConnectionTimeout": Js.Nullable.t(int),
  "useNullAsDefault": Js.Nullable.t(bool),
  "searchPath": Js.Nullable.t(string)
};

[@bs.obj]
external make :
  (
    ~debug: string=?,
    ~client: string=?,
    ~dialect: string=?,
    ~version: string=?,
    ~connection: Connection.t=?,
    ~pool: Pool.t=?,
    ~migrations: Migrations.t=?,
    ~seeds: seeds=?,
    ~acquireConnectionTimeout: int=?,
    ~useNullAsDefault: Js.boolean=?,
    ~searchPath: string=?,
    unit
  ) =>
  t =
  "";

[@bs.obj]
external makeStringConnection :
  (
    ~debug: string=?,
    ~client: string=?,
    ~dialect: string=?,
    ~version: string=?,
    ~connection: Connection.t=?,
    ~pool: Pool.t=?,
    ~migrations: Migrations.t=?,
    ~seeds: seeds=?,
    ~acquireConnectionTimeout: int=?,
    ~useNullAsDefault: Js.boolean=?,
    ~searchPath: string=?,
    unit
  ) =>
  t =
  "";
