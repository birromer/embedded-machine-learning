#include <string>
#include <vector>

std::string cart_predict(std::vector<double> features) {
	if (features[257] <= 114.1) {
		if (features[6] <= 480.153) {
			return ( "classical");
		} else {
			if (features[0] <= 48.876149999999996) {
				return ( "blues");
			} else {
				return ( "jazz");
			}
		}
	} else {
		if (features[487] <= 1.953195) {
			if (features[261] <= 839.7719999999999) {
				if (features[366] <= 65.48225) {
					if (features[271] <= 234.7095) {
						if (features[6] <= 412.35400000000004) {
							if (features[0] <= 90.80865) {
								return ( "classical");
							} else {
								if (features[0] <= 125.04755) {
									return ( "jazz");
								} else {
									return ( "metal");
								}
							}
						} else {
							return ( "blues");
						}
					} else {
						if (features[344] <= 48.5338) {
							if (features[12] <= 196.365) {
								if (features[0] <= 40.0059) {
									return ( "jazz");
								} else {
									return ( "country");
								}
							} else {
								return ( "blues");
							}
						} else {
							if (features[2] <= 553.6895) {
								return ( "blues");
							} else {
								return ( "country");
							}
						}
					}
				} else {
					return ( "blues");
				}
			} else {
				return ( "blues");
			}
		} else {
			if (features[12] <= 568.1485) {
				if (features[2] <= 1720.67) {
					if (features[209] <= 25.3694) {
						if (features[504] <= 7.85025) {
							if (features[0] <= 95.21285) {
								return ( "jazz");
							} else {
								if (features[0] <= 150.45049999999998) {
									return ( "classical");
								} else {
									if (features[0] <= 166.745) {
										return ( "metal");
									} else {
										if (features[0] <= 200.09949999999998) {
											return ( "disco");
										} else {
											return ( "country");
										}
									}
								}
							}
						} else {
							if (features[69] <= 28.2746) {
								return ( "classical");
							} else {
								return ( "hiphop");
							}
						}
					} else {
						return ( "disco");
					}
				} else {
					if (features[16] <= 538.068) {
						if (features[27] <= 465.6515) {
							return ( "hiphop");
						} else {
							return ( "jazz");
						}
					} else {
						if (features[0] <= 343.047) {
							return ( "country");
						} else {
							return ( "disco");
						}
					}
				}
			} else {
				if (features[164] <= 923.906) {
					if (features[92] <= 939.249) {
						if (features[74] <= 931.63) {
							if (features[163] <= 931.3245) {
								if (features[327] <= 498.32349999999997) {
									if (features[43] <= 932.6320000000001) {
										if (features[59] <= 152.5615) {
											if (features[13] <= 639.8675000000001) {
												if (features[0] <= 148.21699999999998) {
													return ( "classical");
												} else {
													return ( "disco");
												}
											} else {
												return ( "jazz");
											}
										} else {
											if (features[12] <= 946.269) {
												return ( "country");
											} else {
												return ( "jazz");
											}
										}
									} else {
										if (features[4] <= 959.2565) {
											if (features[0] <= 836.241) {
												return ( "metal");
											} else {
												if (features[0] <= 885.0015) {
													return ( "disco");
												} else {
													return ( "hiphop");
												}
											}
										} else {
											return ( "rock");
										}
									}
								} else {
									return ( "reggae");
								}
							} else {
								return ( "pop");
							}
						} else {
							if (features[488] <= 490.5755) {
								if (features[30] <= 922.7935) {
									return ( "rock");
								} else {
									if (features[407] <= 496.2235) {
										if (features[92] <= 908.822) {
											return ( "reggae");
										} else {
											return ( "jazz");
										}
									} else {
										if (features[0] <= 848.8465) {
											return ( "disco");
										} else {
											return ( "hiphop");
										}
									}
								}
							} else {
								if (features[4] <= 946.2545) {
									return ( "hiphop");
								} else {
									if (features[0] <= 869.492) {
										return ( "rock");
									} else {
										if (features[0] <= 893.2525) {
											return ( "metal");
										} else {
											if (features[0] <= 1029.9065) {
												return ( "disco");
											} else {
												return ( "pop");
											}
										}
									}
								}
							}
						}
					} else {
						if (features[349] <= 487.11) {
							if (features[78] <= 940.2840000000001) {
								if (features[14] <= 955.6324999999999) {
									return ( "reggae");
								} else {
									if (features[0] <= 891.3005) {
										return ( "pop");
									} else {
										return ( "rock");
									}
								}
							} else {
								return ( "jazz");
							}
						} else {
							if (features[43] <= 933.1505) {
								if (features[0] <= 846.822) {
									return ( "metal");
								} else {
									if (features[0] <= 858.374) {
										return ( "disco");
									} else {
										return ( "rock");
									}
								}
							} else {
								return ( "reggae");
							}
						}
					}
				} else {
					if (features[404] <= 481.35699999999997) {
						if (features[282] <= 491.28499999999997) {
							if (features[357] <= 494.828) {
								if (features[147] <= 942.3245) {
									return ( "pop");
								} else {
									if (features[0] <= 856.7375) {
										return ( "reggae");
									} else {
										return ( "disco");
									}
								}
							} else {
								if (features[117] <= 943.1745000000001) {
									return ( "jazz");
								} else {
									if (features[0] <= 834.8965000000001) {
										if (features[0] <= 822.222) {
											return ( "pop");
										} else {
											return ( "hiphop");
										}
									} else {
										return ( "country");
									}
								}
							}
						} else {
							if (features[96] <= 925.1624999999999) {
								if (features[0] <= 831.2855) {
									return ( "rock");
								} else {
									return ( "hiphop");
								}
							} else {
								if (features[34] <= 942.7695000000001) {
									if (features[6] <= 953.858) {
										if (features[6] <= 946.2995000000001) {
											if (features[5] <= 930.605) {
												return ( "metal");
											} else {
												if (features[0] <= 839.442) {
													return ( "pop");
												} else {
													return ( "disco");
												}
											}
										} else {
											return ( "jazz");
										}
									} else {
										return ( "country");
									}
								} else {
									return ( "reggae");
								}
							}
						}
					} else {
						if (features[432] <= 488.65150000000006) {
							if (features[27] <= 957.8209999999999) {
								if (features[217] <= 941.0215000000001) {
									if (features[98] <= 919.059) {
										if (features[0] <= 892.573) {
											return ( "pop");
										} else {
											return ( "metal");
										}
									} else {
										if (features[383] <= 484.986) {
											if (features[288] <= 486.79200000000003) {
												if (features[99] <= 938.8530000000001) {
													return ( "reggae");
												} else {
													return ( "jazz");
												}
											} else {
												if (features[51] <= 948.8634999999999) {
													return ( "rock");
												} else {
													return ( "reggae");
												}
											}
										} else {
											if (features[317] <= 482.823) {
												if (features[207] <= 928.979) {
													return ( "disco");
												} else {
													return ( "jazz");
												}
											} else {
												if (features[357] <= 487.0025) {
													return ( "metal");
												} else {
													return ( "pop");
												}
											}
										}
									}
								} else {
									if (features[29] <= 944.194) {
										if (features[37] <= 922.085) {
											if (features[3] <= 937.6455000000001) {
												return ( "pop");
											} else {
												return ( "disco");
											}
										} else {
											if (features[34] <= 949.8655) {
												return ( "rock");
											} else {
												return ( "country");
											}
										}
									} else {
										return ( "metal");
									}
								}
							} else {
								return ( "reggae");
							}
						} else {
							if (features[500] <= 483.795) {
								if (features[476] <= 487.749) {
									if (features[1] <= 930.8375000000001) {
										return ( "jazz");
									} else {
										return ( "disco");
									}
								} else {
									if (features[98] <= 931.8530000000001) {
										return ( "rock");
									} else {
										if (features[5] <= 932.606) {
											return ( "reggae");
										} else {
											if (features[11] <= 929.7615000000001) {
												return ( "metal");
											} else {
												return ( "jazz");
											}
										}
									}
								}
							} else {
								if (features[142] <= 939.7415) {
									if (features[77] <= 918.473) {
										return ( "reggae");
									} else {
										if (features[28] <= 945.8035) {
											if (features[37] <= 921.7294999999999) {
												return ( "jazz");
											} else {
												return ( "metal");
											}
										} else {
											if (features[0] <= 844.3645) {
												return ( "disco");
											} else {
												return ( "rock");
											}
										}
									}
								} else {
									if (features[0] <= 835.8425) {
										return ( "pop");
									} else {
										if (features[0] <= 855.066) {
											return ( "rock");
										} else {
											return ( "hiphop");
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}